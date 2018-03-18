## IPSEC

Una red privada virtual (VPN) proporciona un túnel seguro a través de una red publica (y por lo tanto, insegura). Una VPN proporciona un mecanismo para las organizaciones conectar usuarios y oficinas, sin incurrir en altos costos en la contratacion de una linea dedicada de datos privados


Las VPN se usan con mayor frecuencia sobre Internet, proporcionando a los usuarios acceso a correo electrónico, documentos, impresoras ysistemas como si realmente estuvieran en su oficina central.

Las VPN generalmente se usan con dos propósitos:

- VPN cliente: conecta a los usuarios domésticos o "itinerantes" a una oficina.
- VPN de site 2 site: conecta 2 o mas oficinas remotas a una oficina principal.


¿Qué es IPSEC?

IPSEC, abreviatura de IP Security, es un conjunto de protocolos, estándares y algoritmos para asegurar el tráfico a través de una red que no es de confianza, como Internet por ej.

IPSEC proporciona tres servicios principales:

- Confidencialidad: evita el robo de datos, mediante el cifrado.
- Integridad: garantiza que los datos no se manipulen ni alteren en transito utilizando un algoritmo de hash.
- Autenticación: confirma la identidad del host que envía los datos, utilizando claves precompartidas o una Autoridad de certificación (CA).
- Anti-replay: evita la duplicación de paquetes cifrados, al asignar un número de secuencia único.

El estándar IPSEC se describe en RFC 2401











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
