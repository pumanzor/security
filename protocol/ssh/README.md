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




