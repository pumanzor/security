## IPSEC

Una red privada virtual (VPN) proporciona un túnel seguro a través de una red publica (y por lo tanto, insegura). Una VPN proporciona un mecanismo para las organizaciones conectar usuarios y oficinas, sin incurrir en altos costos en la contratacion de una linea dedicada de datos privados


Las VPN se usan con mayor frecuencia sobre Internet, proporcionando a los usuarios acceso a correo electrónico, documentos, impresoras ysistemas como si realmente estuvieran en su oficina central.

Las VPN generalmente se usan con dos propósitos:

- VPN cliente: conecta a los usuarios domésticos o "itinerantes" a una oficina.
- VPN de site 2 site: conecta 2 o mas oficinas remotas a una oficina principal.


### ¿Qué es IPSEC?

IPSEC, abreviatura de IP Security, es un conjunto de protocolos, estándares y algoritmos para asegurar el tráfico a través de una red que no es de confianza, como Internet por ej.

IPSEC proporciona tres servicios principales:

- Confidencialidad: evita el robo de datos, mediante el cifrado.
- Integridad: garantiza que los datos no se manipulen ni alteren en transito utilizando un algoritmo de hash.
- Autenticación: confirma la identidad del host que envía los datos, utilizando claves precompartidas o una Autoridad de certificación (CA).
- Anti-replay: evita la duplicación de paquetes cifrados, al asignar un número de secuencia único.

El estándar IPSEC se describe en RFC 2401

### Confidencialidad y Encriptación

Los datos enviados en texto claro a través de Internet pueden ser interceptados y robados. Debido a esto, los datos confidenciales deben ser cifrados cuando se envían a través de una red o dominio no confiable.

Las claves son valores generados que se utilizan para cifrar y descifrar datos. Mientras mas larga la clave, más segura es esa clave. La longitud de una clave se mide en bits.

Existen dos "tipos" de claves:

- Claves simétricas: se pueden utilizar para cifrar y descifrar datos. Más específicamente, la misma clave se utiliza para cifrar un paquete (en el origen) y luego descifrar ese paquete (en el destino). El cifrado de llave simetrica es eficiente, pero no escala bien en entornos grandes.

Las claves simétricas no se comparten abiertamente durante la transmisión de datos, y en su lugar deben ser instaladas en cada máquina antes de la transferencia de datos. Esto puede ser logrado usando una variedad de métodos (ineficientes e inseguros): por ejemplo ; correo electrónico, 


- Claves asimétricas: requieren una clave separada para el cifrado (la clave pública) y descifrado (la clave privada). Las claves públicas se intercambian abiertamente entre dispositivos para cifrar datos durante la transferencia. Las claves privadas nunca se intercambian.


El intercambio de claves públicas mediante el algoritmo Diffie-Hellman (DH) es el estándar más común utilizado para crear e intercambiar claves en medios inseguros. DH no se usa para cifrar datos, sino para generar las claves que se utilizan para cifrar y descifrar datos.

Una variedad de estándares y protocolos populares utilizan el intercambio de claves DH, incluyendo SSL (Secure Socket Layer), SSH (Secure Shell) e IPSEC. Las claves públicas generadas cifran la carga útil de datos (payload) usando uno de varios
Algoritmos de cifrado disponibles:


- DES (Data Encryption Standard) – 56-bit key
- 3DES (Triple Data Encryption Standard) – 168-bit key
- AES (Advanced Encryption Standard) - 128, 192, or 256-bit key
- Blowfish – up to a 448-bit key

Además, la fuerza de una clave está determinada por el grupo DH utilizado para generar esa clave. Hay varios grupos DH:

- DH Group 1—768-bit modulus
- DH Group 2—1024-bit modulus
- DH Group 5—1536-bit modulus
- DH Group 14—2048-bit modulus
- DH Group 19—256-bit modulus elliptic curve
- DH Group 20—384-bit modulus elliptic curve
- DH Group 24—2048-bit modulus with 256-bit prime order subgroup

Debido a que el módulo para cada grupo DH es de un tamaño diferente, los participantes deben estar de acuerdo para usar el mismo grupo


### Integridad de datos y Hashing

Los datos enviados a través de Internet no solo pueden ser robados, sino que también pueden ser maliciosamente alterados.
Para combatir esto en PISEC se emplea un algoritmo hash que calcula y agrega un valor hash específico a medida que se envía cada paquete. 

Una vez que se reciben los datos en el receptor, se calcula nuevamente a través del mismo algoritmo de hash acordado en la fases de negociacion por cada paquete recibido. Si el valor de hash es diferente, el paquete fue alterado en tránsito.

Para realizar lo anterior se utiliza el código de autenticación de mensajes hash (HMAC). HMAC utiliza una clave secreta al momento de computar el valor del hash, evitando así que un atacante altere el paquete y luego re-compute el hash correcto.

Dos algoritmos HMAC se usan comúnmente:

- HMAC-MD5 (Message-Digest 5) – 128-bit hashed key
- HMAC-SHA1 (Secure Hash Algorithm) – 160-bit hashed key

### Autenticación

Otra preocupación al enviar datos a través de Internet es la fuente o el origen de esos datos ya que es posible enmascarar o falsificar la identidad o dirección.

Para que se establezca un túnel IPSEC VPN, ambos lados del túnel deben estar autenticados, para lograr esto, una clave pre-compartidad (pre-shared key) o una firma RSA digital debe ser ser configurada al momento de crear el tunel.

Al usar claves precompartidas, se utiliza una cadena de texto secreta en cada dispositivo para autenticarse el uno al otro. Esta cadena debe ser previamente acordada e idéntica en cada dispositivo, luego a partir de esta cadena de texto se genera un hash de una firma digital.

En el caso de utilizar firmas RSA Digital en vez de la opcion anterior, se debe requerir una Autoridad de Certificación (CA) para verificar este tipo de firmas

Luego para que el tunel se establezca y pase a modo activo una de las 2 opciones anteriores debe ser configurada correctamente.



### Autoridades de certificación (CA)

Recuerde que existen dos métodos para autenticar un túnel IPSEC:

- Al usar claves precompartidas (pre-shared key), se usa una cadena de texto secreta en cada dispositivo para autenticarse el uno al otro. Esta cadena debe ser previamente acordada e idéntica en cada dispositivo. Esta cadena se convierte en hash de una firma digital.

- Al usar firmas RSA Digital, se utiliza una Autoridad de Certificación (CA) (o third party) para veridicar una firma digital. Esto proporciona una solución más escalable que las claves precompartidas.


### Protocolos IPSEC

IPSEC utiliza uno de dos encabezados de protocolo para proteger datos:

- Authentication Header (AH)
- Encapsulation Security Payload (ESP)


Authentication Header (AH), o protocolo IP 51 (Iana), no proporciona confidencialidad de los datos. No cifre ningún dato en absoluto. Sin embargo, AH proporciona servicios de autenticación e integridad. Debido a que AH no realiza cifrado, es un estándar más rápido que ESP.

AH usa un algoritmo hash para calcular un valor hash en la carga útil y encabezado de un paquete, asegurando la integridad de este. Sin embargo, esto causa un problema muy específico ya que no funcionará a través de un dispositivo NAT.

NAT cambia el encabezado IP de un paquete durante la traducción, pero el valor hash no ha cambiado; por lo tanto, el dispositivo receptor creerá que el paquete ha sido alterado en tránsito y por ende rechazara el paquete.


Encapsulation Security Payload (ESP) (ESP), o protocolo IP 50 (IANA), realiza servicios de confidencialidad, autenticación e integridad. Por lo tanto, ESP realiza cifrado y es intrínsecamente más seguro que AH. 

ESP introduce un header y un trailer al paquete, ademas también utiliza un algoritmo hash para la integridad de datos. Sin embargo, el hash no incluye el header IP del paquete y por lo tanto, el ESP (generalmente) funcionará
a través de un dispositivo NAT.

ESP y AH pueden usarse por separado o usarse conjuntamente.

### Modos transporte y tunel

Cada protocolo IPSEC (AH o ESP) puede operar en uno de dos modos:

- Modo transporte: los encabezados IP originales se dejan intactos. Este modo se utiliza cuando se requiera asegurar la comunicación de un dispositivo con otro dispositivo de manera individual.

- Modo túnel: todo el paquete original está codificado y / o cifrado, incluyendo tanto la carga útil como los encabezados originales. Una IP temporal en el header se aplica al paquete durante el tránsito. Se usa para canalizar el tráfico desde
un sitio a otro.


ESP en modo Túnel puede experimentar dificultades NAT similares a AH. Esto puede se solucionado implementando NAT Traversal (NAT-T).


### Asociaciones de seguridad IKE e IPSEC (SA)

Los pares o peers VPN IPSEC establecen una Security Association (SA) que es una "conexión" o "Política" entre los dos puntos finales del túnel VPN. Una SA es un túnel virtual de una via entre los peers VPN. Por lo tanto, para que ocurra una comunicación completa bidireccional se deben establecer dos SA, una para cada dirección.

Antes de que se pueda establecer una SA varios parametros se deben negociar entre los peers VPN ademas incluyendo las claves las cuales deben ser creadas e intercambiadas. 

El protocolo de intercambio de claves de Internet (IKE) controla este proceso de negociación utilizando el puerto UDP 500.

Los conjuntos de políticas IKE se crean para negociar varios parámetros los cuales incluyen:

- El algoritmo de cifrado (como DES, 3DES o AES)
- El algoritmo hash (como MD5 o SHA-1)
- El método de autenticación (como claves compartidas o firmas RSA)
- El grupo Diffie-Hellman (D-H) para crear y compartir claves
- El SA Lifetime, medido en segundos o en kilobytes enviados


Las políticas IKE a menudo se conocen como "Internet Security Association and Key Management Protocol o (ISAKMP) y múltiples políticas IKE pueden ser creadas en un tunel VPN. 

Durante el proceso de negociación, los peers VPN comparten su lista configurada de políticas IKE. La SA solo se establecerá si hay coincidencia exacta entre los peers.

Existen dos fases en este proceso de negociación:

IKE fase 1: la cual establece el túnel inicial (denominado IKE o ISAKMP SA). en esta etapa los peers son autenticados, algoritmos de autenticacion y hashing se negocian y las claves se intercambian en función de los conjuntos de políticas IKE. 

Dos modos se pueden utilizar para la negociación de la Fase 1:

- Modo principal: más lento, pero más seguro
- Modo agresivo: más rápido, pero menos seguro

IKE fase 2: establece el túnel IPSEC (IPSEC SA), que detalla los parámetros AH o ESP para proteger los datos. Estos parámetros están contenidos en el IPSEC transform Set.

#### en resumen

IKE fase 1 negocia los parámetros para el túnel (intercambio de claves) en sí, mientras que IKE Phase 2 negocia los parámetros para los datos que atraviesan ese túnel.


La operacion de IPSEC en una VPN se puede resumir en los siguientes pasos:

1. Cualquier tráfico que debe ser asegurado y enviado a través del túnel es identificado como tráfico interesante, usualmente usando una lista de acceso.

2. IKE (Internet Key Exchange) la Fase 1 es iniciada. Los peers son autenticados, las claves se intercambian y los conjuntos de políticas IKE son negociados - Si tiene éxito, se establece IKE SA.

3. IKE (Internet Key Exchange) la Fase 2 se inicia. IPSEC transform sets son negociadas y si tienen éxito, se establece el IPSEC SA.

4. Los datos se transfieren utilizando la política de seguridad acordada.

5. La sesión se cancela una vez que vence el SA Lifetime





--------------------------------------

















## trash
-------------------------

##Security at the Network Layer: IPSec

###Provides Layer 3 security (RFC 2401)
- Transparent to applications (no need for integrated IPSec support)

###Objetives

- Protect the IP header content against active or passive attacks using:
  - Header authentication
  - Encrypting Content

###IPsec features & benefits
- Confidentiality
  - By encrypting data (cifrado)
- Integrity
  - Routers at each end of a tunnel calculates the checksum or hash value of the data
- Authentication
  - Signatures and certificates
  - All these while still maintaining the ability to route through existing IP networks

###A set of protocols and algorithms used to secure IP data at the network layer

###Combines different components:
- Security associations (SA)
- [Two Security protocols , Authentication headers (AH) and Encapsulating security payload (ESP) ](https://github.com/pumanzor/security/blob/master/protocol/ipsec/security_protocol.md)
- Internet Key Exchange (IKE)

###A security context for the VPN tunnel is established via the ISAKMP

##IPSEC Architecture

![alt tag](https://github.com/pumanzor/security/blob/master/protocol/ipsec/img/arquitectura1.jpg)

##IPSEC Modes

[Transport Mode](https://github.com/pumanzor/security/blob/master/protocol/ipsec/transport_mode.md)

[Tunnel Mode](https://github.com/pumanzor/security/blob/master/protocol/ipsec/tunnel_mode.md)

![alt tag](https://github.com/pumanzor/security/blob/master/protocol/ipsec/img/tunnel_vs_transport.jpg)

##SA Security Asociations
