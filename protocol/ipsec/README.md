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
