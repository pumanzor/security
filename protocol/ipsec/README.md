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
