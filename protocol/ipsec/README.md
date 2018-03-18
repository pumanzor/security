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

- Group 1 – 768 bits
- Group 2 – 1024 bits
- Group 5 – 2048 bits


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

Para que se establezca un túnel IPSEC VPN, ambos lados del túnel deben estar autenticados, para lograr esto, una clave pre-compartidad (pre-shared key) o una firma RSA digital deben ser ser configuradas al momento de crear el tunel.

Al usar claves precompartidas, se usa una cadena de texto secreta en cada dispositivo para autenticarse el uno al otro. Esta cadena debe ser previamente acordada e idéntica en cada dispositivo, luego a partir de esta clave se genera un hash dentro de una firma digital.

Al usar firmas RSA Digital, se utiliza una Autoridad de Certificación (CA) para verificar este tipo de firmas

para que el tunel se establesca y pase a modo activo una de las 2 opciones anteriores debe ser configurada correctamente.




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
