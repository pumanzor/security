##Security at the Network Layer: IPSec

###Benefits of IPsec
- Confidentiality
  - By encrypting data
- Integrity
  - Routers at each end of a tunnel calculates the checksum or hash value of the data
- Authentication
  - Signatures and certificates
  - All these while still maintaining the ability to route through existing IP networks

###Provides Layer 3 security (RFC 2401)
- Transparent to applications (no need for integrated IPSec support)

###A set of protocols and algorithms used to secure IP data at the network layer

###Combines different components:
- Security associations (SA)
- Authentication headers (AH)
- Encapsulating security payload (ESP)
- Internet Key Exchange (IKE)

###A security context for the VPN tunnel is established via the ISAKMP

##IPSEC Architecture

![alt tag](https://github.com/pumanzor/security/blob/master/protocol/ipsec/img/arquitectura1.jpg)

##IPSEC Modes

###Transport Mode

###Tunnel Mode

