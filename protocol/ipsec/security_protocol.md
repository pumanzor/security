##Security protocol AH Authentication Header

![alt tag](https://github.com/pumanzor/security/blob/master/protocol/ipsec/img/ah_header_v1.jpg)

###AH provides:
- data integrity (intacto, entero) 
- authentication

> Does not provide encryption

- Uses one-way hash function (also called an HMAC) to guarantee data integrity and origin of the packet.
- Entire IP packet put through one-way hash.
- Includes IP header which could lead to problems.
- TTL must be “zeroized: to give a “standard header”
- Produces a new AH header for the packet to be transmitted.
- AH may be applied alone, in combination with the IP ESP.



##Security protocol ESP Encapsulating Security Payload

> ESP is primarily used to provide payload encryption.

- With current revisions of the RFC, it also includes the ability for authentication and integrity.
- Because ESP can include all three services, authentication, integrity, and encryption, most implementations do not include an AH options.
- IPSec can use different algorithms for payload encryption such as:
  - DES
  - 3DES
  - AES
- Uses IP protocol 50
- Provides all that is offered by AH, plus data confidentiality (by encrytion)
  - It uses symmetric key encryption
- Must encrypt and/or authenticate in each packet
  - Encryption occurs before authentication
- Authentication is applied to data in the IPsec header as well as the data contained as payload

