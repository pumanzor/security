### Protocolo SSH

SSH o Secure SHell es un procolo que trabaja en la capa 7 del modelo OSI y que tiene por objetivo corregir las deficiencias conocidas en los protocolos FTP, TELNET, RSH y RCP a traves de 3 sub-protocolos:


- SSH-USERAUTH, un protocolo de autenticacion del lado cliente – RFC 4252.

- SSH-TRANS, un protocolo de transferencia segura que permita una autenticacion del servidor y el establecimiento de un canal seguro (confidencialidad e integridad) – RFC 4253.

- SSH-CONNECT, un protocolo de conexion que permita una multiplexacion de canales de comunicacion (datos y comandos)

------

SSH se encuentra estandarizada desde el 2006 por el set de RFCs 4250 al 4254 en donde se especifica los protocolos de comunicacion y los mecanismos de cifrado que debe soportar.

SSH existe 2 versiones: SSHv1 y SSHv2. SSHv1 tiene vulnerabilidades estructurales que han sido corregidas en la siguiente version
, por lo tanto esta version se encuentra obsoleta.

SSH es principalmente un protocolo de comunicacion, no es ni un unix shell o terminal ni un interprte de comandos.

> OpenSSH es la implementación más comúnmente encontrada del protocolo SSH. Más que un protocolo, es una caja de herramientas que ofrece una gran cantidad de características.

### Presentación de OpenSSH

OpenSSH es desarrollado y mantenido por el proyecto OpenBSD. Es, hasta la fecha, la referencia de implementación del protocolo SSH encontrado en una gran cantidad de sistemas, incluidos servidores (Unix,GNU / Linux, Windows), máquinas cliente y dispositivos de red.

Este paquete de software incluye muchas herramientas:

* el servidor, sshd.
* varios clientes, dependiendo de la finalidad:
    - conexiones de shell remotas: ssh;
    - transferencias de archivos y descargas: scp, sftp;
* una herramienta de generación de claves, ssh-keygen;
* un servicio de keyring (llavero), ssh-agent y ssh-add;
* una utilidad para reunir las claves de host SSH públicas de varios hosts, ssh-keyscan.


### Casos de uso

#### Administración remota de shell

La administración remota es el uso más frecuente de SSH. Consiste en conectarse de manera remota a un host (computador, servidor, equipo, laptop.etc) distante y luego la apertura de una sesión de shell remoto post autenticación exitosa.

La ventaja obvia de SSH es su seguridad. Considerando que telnet no proporciona autenticación de servidor
ni un canal encriptado y autenticado, SSH lo hace, siempre y cuando se sigan unas reglas basicas de seguridad.

#### Transferencias y descargas de archivos.

El segundo uso más común de SSH es la transferencia de archivos, tanto para la carga (cliente a servidor) y para la descarga (servidor a cliente).

SSH proporciona dos mecanismos para este fin: SCP y SFTP. SFTP es más elaborado que SCP ya que permite la navegación en un árbol de archivos, mientras que SCP simplemente permite la transferencia de datos. En ambos casos, la seguridad se basa principalmente en SSH, que proporciona el canal de comunicación seguro.

Desde el punto de vista de la red, el uso de SCP / SFTP simplifica la configuración de las reglas de filtrado en comparacion con FTP ya que permite multiplexar el canal de datos y el canal de control en la misma conexion SSH, por lo que no hay necesidad de una regla de apertura de puerto dinámico, como se requiere con FTP.


#### Reenvío de flujo (Flow forwarding)

El reenvío de flujo SSH también se usa comúnmente. Consiste en encapsular flujos de TCP / IP directamente
en el túnel SSH, para permitir (entre otras cosas) el transporte seguro de un protocolo no segur o para proporcionar acceso a servicios protegidos por un gateway.

> La implementación de túneles SSH solo se aplicará a los protocolos que no brinden mecanismos de seguridad robustos y que pueden beneficiarse de ello (por ejemplo: X11, VNC). Esta recomendación no está exenta de usar protocolos de seguridad de bajo nivel adicionales, como IPsec.


### Mejores prácticas para usar OpenSSH

#### Criptografía

##### Autenticación
SSH depende en gran medida de la criptografía asimétrica para la autenticación. Si no se garantiza la autenticación del servidor, se pueden producir numerosos impactos de seguridad:

- riesgo de robo de datos a través de la suplantación del servidor (imposibilidad de verificar la identidad del servidor)

- exposición a ataques de "hombre en el medio" que permite recuperar todos los datos intercambiados (pulsaciones de teclas,
elementos mostrados, inicios de sesión, contraseñas, archivos vistos o editados.).

> La autenticidad del servidor siempre se comprobará antes de acceder a el. Esto se logra a través de
autenticación preliminar de la máquina al verificar la huella digital de la clave pública del servidor (fingerprint) o
verificar el certificado del servidor (mediante PKI).

-------

Con OpenSSH, el cliente puede lograr este control de diferentes maneras:

- Asegúrese de que la huella digital de clave pública SSH del servidor (fingerprint) sea la correcta , es puede obtener mediante la ejecucion del comando ssh-keygen -lf llave_publica

- Agregando manualmente la clave pública del servidor SSH en el archivo known_hosts del cliente.
- Verificar la firma del certificado SSH presentado por el servidor con un certificado de confianza o autoridad de Certificación CA.

La validación explícita de la clave de host por parte del usuario se puede especificar utilizando el Atributo StrictHostKeyChecking en el archivo de configuracion sshd_config:

    StrictHostKeyChecking ask
    
    
OpenSSH aplica de forma predeterminada, un modelo de seguridad de Confianza en el primer uso (Trust of first Use ,TOFU) - durante la primera conexión, si el cliente no puede autenticar el host remoto es decir no encuentra el fingerprint del server en su archivo known_hosts, ssh solicita al usuario que verifique el fingerprint del servidor

Si el usuario valida este fingerprint o huella digital, ssh lo registrara en el archivo known_hosts para permitir la validación automática de las siguientes conexiones.


#### Generación de claves: tamaños y algoritmos

SSH puede manejar varios algoritmos criptográficos y tamaños de clave. Algunos de ellos no cumplen con los requisitos de seguridad deseados a la fecha.

En la práctica, las claves (fingerprint) de un host SSH (utilizadas para autenticar un servidor SSH) raramente se renuevan. Es
por lo tanto, importante elegir una clave lo suficientemente larga desde el principio.

La implementación de DSA en OpenSSH admite claves de hasta 1024 bits de longitud. Tales llaves son ahora
consideradas inseguras y su uso es fuertemente desaconsejado.

Los algoritmos que ud debiera utilizar para cumplir con los requisitos actuales de seguridad son RSA y ECDSA y como minino el tamaño de la llave para RSA debe ser de 2048 mientras que para ECDSA es 256 bits.

--------
Ejemplo, como generar par de llaver publica/privada en Openssh Linux

    RSA
    ssh-keygen -t rsa-b 2048 

    ECDSA
    ssh-keygen -t ecdsa -b 256 
    
con la accion anterior ssh-keygen generara 2 archivos: la llave privada y la llave publica esta ultima tendra como extension .pub

> como saber que tipo de llave es uno u otro archivo?, ejecute el comando file * dentro del directorio donde ejecuto el comando ssh-keygen

    file *

    id_ecdsa:        PEM EC private key
    id_ecdsa.pub:    OpenSSH ECDSA public key

#### Autenticación y control de acceso de usuario

#### Autenticacion de usuario
Se pueden usar varios mecanismos para autenticar a los diferentes usuarios. La autenticación del usuario debe realizarse con uno de los siguientes mecanismos por orden de preferencia:

- Criptografía asimétrica ECDSA;
- Criptografía asimétrica RSA;
- Criptografía simétrica (tickets de Kerberos desde GSSAPI);
- módulos de autenticación que no exponen ni la contraseña del usuario ni su hash (de terceros) Módulos PAM o BSD Auth);
- verificación de contraseñas en una base de datos (como passwd / shadow) o un directorio.

> En todos los casos, la autenticación con contraseña no se debe usar para usuarios altamente privilegiados.

Mecanismos de criptografía asimétrica (ECDSA, RSA) son proporcionados directamente por el toolbox de OpenSSH. 

Los dueños de las llaves publicas que se encuentren listados dentro del archivo

    authorized_keys
    
de la cuenta del usuario le sera concedido el acceso al sistema bajo esta cuenta.

Las cuentas de usuario siempre tienen derechos en el sistema, sin importar cuán mínimos sean. Su acceso debe ser autenticado y los ataques de fuerza bruta deben ser mitigados.

