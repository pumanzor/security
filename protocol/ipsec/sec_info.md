Authentication Header (AH, Encabezamiento de autenticación): protocolo de seguridad que proporciona servicios de autenticación y detección de reproducción opcional. AH se ha incluido en los datos que se van a proteger (un datagrama de IP completo, por ejemplo). Es posible utilizar AH tanto solo como con la carga útil del servicio de cifrado (ESP). Consulte la sección RFC 2402leavingcisco.com.

Autenticación: esta es una de las funciones desde la estructura IPSec. La autenticación establece la integridad de los datos y asegura que no se verán alterados durante el tránsito. También proporciona una confirmación del origen de los datos.

Certification Authority (CA, Autoridad de certificación): una tercera entidad con la responsabilidad de emitir y revocar certificados. Cada dispositivo que tiene su propio certificado y la clave pública de la CA, puede autenticar cualquier otro dispositivo en un dominio de la CA. Este término también se aplica al software del servidor que proporciona dichos servicios.

Certificado: objeto firmado criptográficamente que contiene una identidad y una clave pública asociada a dicha identidad.

Criptografía clásica: mecanismo de cifrado propiedad de Cisco utilizado en la versión 11.2 del software Cisco IOS®. La criptografía clásica está disponible en la versión 11.3 del software Cisco IOS. Sin embargo, IPSec no se “retroadapta” a la versión 11.2 del software Cisco IOS. También verá el nombre "criptografía clásica" referida como "cifrado exprés" o "tecnología de cifrado de Cisco" (CET) en la documentación de marketing.

Certificate Revocation List (CRL, Lista de revocación de certificados): mensaje firmado de forma digital que muestra una lista con todos los certificados actuales pero revocados para una CA. Esto es análogo a un libro de números de tarjetas robadas que permite a los almacenes rechazar las tarjetas de crédito.

Correspondencia de criptografía: entidad de configuración del software Cisco IOS que realiza dos funciones principales. Primero, selecciona flujos de datos que necesitan un proceso de seguridad. Segundo, define la política para esos flujos y la entidad criptográfica a la que debe ir el tráfico.

La correspondencia de criptografía se aplica a una interfaz. El concepto de correspondencia de criptografía se introdujo en la criptografía clásica, pero se expandió para IPSec.

Integridad de datos: mecanismos de integridad de datos, mediante el uso de algoritmos basados en clave secreta o clave pública, que permiten al receptor de un conjunto de datos protegidos verificar que los datos no se han modificado durante el tránsito.

Confidencialidad de datos: método mediante el cual los datos protegidos se manipulan de modo que ningún atacante pueda leerlos. Esto se logra comúnmente a través del cifrado de datos y claves que sólo están disponibles para las partes que participan en la comunicación.

Autenticación del origen de los datos: servicio de seguridad en el que el receptor puede verificar que los datos protegidos los ha originado sólo el emisor. Este servicio necesita un servicio de integración de datos además de un mecanismo de distribución de clave, en donde sólo el emisor y el receptor comparten una clave secreta.

Data Encryption Standard (DES, Estándar de cifrado de datos): la DES se publicó en 1977 por la oficina nacional de estándares y es un esquena de cifrado de claves secretas basado en el algoritmo Lucifer de IBM. El contraste de DES es una clave pública. Cisco utiliza DES en la criptografía clásica (longitudes de clave de 40 y 56 bits), cifrado de IPSec (clave de 56 bits) y en el Firewall PIX (clave de 56 bits).

Diffie-Hellman: método mediante el cual se establece una clave compartida en un medio inseguro. Diffie-Hellman es un componente de Oakley (consulte la definición de Oakley que se encuentra en esta lista de definiciones).

DSS: algoritmo de firma digital diseñado por el instituto nacional de estándares y tecnología (NIST) basado en la criptografía de clave pública. DSS no realiza el cifrado del datagrama de usuario. DSS es un componente de la criptografía clásica, así como la tarjeta Redcreek IPSec, pero no se ha implementado en el software Cisco IOS.

Adaptador del servidor de cifrado (ESA): hardware basado en la aceleración de cifrado que se utiliza en los

    Routers 7204 y 7206 de Cisco

    Procesador 2-40s de interfaz virtual (VIP2-40) de segunda generación en todos los routers de la serie 7500 de Cisco

    VIP2-40 en los routers de la serie 7000 de Cisco que tengan el Router Switch Processors de Cisco (RSP7000) y las tarjetas interfaz (RSP7000CI) de chasis serie 7000 de Cisco instaladas. 

IPSec no utiliza la aceleración ESA, pero trabaja con un equipo que incluye una tarjeta ESA en forma de sólo software.

Carga útil de seguridad encapsulada (ESP): protocolo de seguridad que proporciona confidencialidad de datos y protección con servicios de autenticación y detección de reproducción opcionales. ESP encapsula completamente los datos del usuario. ESP puede utilizarse sólo o junto con AH. Consulte RFC 2406: Carga útil de seguridad encapsulada (ESP)leavingcisco.com.

Hash: función unidireccional que coge un mensaje de entrada con una longitud arbitraria y produce un resumen con una longitud fija. Cisco utiliza tanto Secure Hash Algorithm (SHA) como Message Digest 5 (MD5) en la implementación de la estructura IPSec (consulte la definición de HMAC).

HMAC: mecanismo de autenticación de mensajes mediante hashes criptográficos como SHA y MD5. Para un debate más exhaustivo de HMAC, consulte RFC 2104leavingcisco.com.

Internet Key Exchange (IKE, Intercambio de claves de Internet): protocolo híbrido que utiliza una parte del protocolo Oakley y otra parte de un conjunto de protocolos llamado SKEME en el marco de la Asociación de seguridad en Internet y el Protocolo de administración de claves (ISAKMP). IKE se utiliza para establecer una política de seguridad compartida y las claves autenticadas para los servicios (como IPSec) que requieren una clave. Antes de que se pueda transmitir cualquier tráfico de IPSec, cada router, firewall o host debe ser capaz de identificar la identidad de su par: es posible realizarlo manualmente introduciendo claves previamente compartidas en ambos hosts, por un servicio de CA, o el próximo DNS seguro (DNSSec). Este es el protocolo que antiguamente se conocía como ISAKMP/Oakley, y se define en RFC 2409: Intercambio de claves de Internet (IKE)leavingcisco.com. Un punto de confusión importante es que ambos acrónimos, "ISAKMP" e "IKE", se utilizan en el software Cisco IOS para referirse al mismo concepto. Sin embargo, estos dos elementos son algo diferentes.

Internet Security Association and Key Management (ISAKMP, Asociación de seguridad en Internet y Protocolo de administración de claves): estructura de protocolo que define el mecanismo de implementación de un protocolo de intercambio de claves y la negociación de las políticas de seguridad. ISAKMP se define en la Asociación de seguridad en Internet y el Protocolo de administración de claves.

Transparencia IPSec NAT: la función de transparencia IPSec NAT incorpora el soporte para el tráfico de seguridad IP(IPSec) para circular a través de la traducción de direcciones de red (NAT) o puntos de traducción de direcciones de punto (PAT) de la red resolviendo diversas incompatibilidades conocidas entre NAT e IPSec. NAT Traversal es una característica que los dispositivos VPN autodetectan. No hay que seguir ningún paso para configurar un router que ejecute la versión 12.2(13)T y superiores del software Cisco IOS. Si ambos dispositivos VPN son compatibles con NAT-T, NAT Traversal se autodetectará y autonegociará.

ISAKMP/Oakley: Consulte IKE.

Message Digest 5(MD5): algoritmo de generación de hash unidireccional que produce un hash de 128 bits. Tanto MD5 como el Algoritmo de hash seguro (SHA) son variaciones del MD4, que se diseñó para reforzar la seguridad de este algoritmo de generación de hash. SHA es más seguro que MD4 y MD5. Cisco utiliza hashes para la autenticación dentro del marco IPSec.

Oakley: protocolo de intercambio de claves que define cómo adquirir material de codificación autenticado. El mecanismo básico de Oakley es el algoritmo Diffie-Hellman de intercambio de claves. Podrá encontrar la norma en RFC 2412: Protocolo de determinación de clave OAKLEYleavingcisco.com.

Perfect Forward Secrecy (PFS, Confidencialidad directa perfecta): PFS asegura que una clave IPSec SA no se ha derivado de otra clave secreta (como otra clav independiente) En otras palabras, si alguien interrumpe una clave, PFS asegura que el atacante no pueda derivar ninguna otra clave. Si no se habilita PFS, alguien podría interrumpir la clave secreta de IKE SA, copiar todos los datos protegidos de IPSec y, a continuación, hacer uso de la clave IKE SA para comprometer la configuración del IPSec SA con la IKE SA. Con PFS, la interrupción de IKE no dará al atacante un acceso inmediato a IPSec. Será necesario que el atacante interrumpa cada IPSec SA individualmente. La implementación de IPSec en el Cisco IOS utiliza PFS del grupo 1 (D-H 768 bit) de forma predeterminada.

Detección de reproducción: servicio de seguridad en el que el receptor puede rechazar paquetes antiguos o duplicados para evitar ataques con paquetes reproducidos (los ataques con paquetes reproducidos consisten en que el atacante envía paquetes antiguos o duplicados al receptor y que éste último crea que el tráfico falso es legítimo). La detección de reproducción se realiza mediante números de secuencia combinados con la autenticación, y es una característica estándar de IPSec.

RSA: algoritmo criptográfico de clave pública (nombrado con el nombre de sus inventores Rivest, Shamir y Adleman) con una clave de longitud variable. La principal desventaja de RSA es que es muy lenta para computar en comparación con los algoritmos populares de clave secreta, como DES. La implementación de IDE de Cisco utiliza el intercambio Diffie-Hellman para obtener claves secretas. Este intercambio puede autenticarse con RSA (o claves previamente compartidas). Con el intercambio Diffie-Hellman, la clave DES nunca recorre la red (ni siquiera de forma cifrada), lo que sí ocurre con la técnica de cifrado y firma RSA. RSA no es un dominio público, y debe tener licencia de RSA Data Security.

Security Association (SA, Asociación de seguridad): instancia de política de seguridad y material de codificación que se aplica al flujo de datos. Tanto IKE como IPSec utilizan SA, aunque cada una de las SA son independientes entre ellas. Los SA de IPSec son unidireccionales y únicos en cada protocolo de seguridad. Se necesita un conjunto de SA para un conducto de datos protegidos, uno por cada dirección del protocolo. Por ejemplo, si tiene un conducto que soporte ESP entre pares, es necesario una ESP SA para cada dirección. Los SA se identifican por la dirección de destino (punto final del IPSec), el protocolo de seguridad (AH o ESP) y el índice de parámetros de seguridad (SPI).

IKE negocia y establece los SA en nombre de IPSec. Un usuario también puede establecer un SA de IPSec manualmente.

Un SA de IKE se utiliza sólo para IKE. A diferencia de los SA de IPSec, que son bidireccionales.

Algoritmo de hash seguro (SHA): hash unidireccional propuesto por NIST. SHA se basa en MD4 y produce un digest de 160 bits. Puesto que SHA produce un digest de 160 bits, es más resistente a los ataques que los hashes de 128 bits (como el MD5), pero es más lento.

Transformación: una transformación describe un protocolo de seguridad (AH o ESP) con sus correspondientes algoritmos. Por ejemplo, ESP con el algoritmo de cifrado DES y HMAC-SHA para la autenticación.

Modo de transporte: modo de encapsulación para AH/ESP. El modo de transporte encapsula el segmento de datos de la capa superior (como el Protocolo de control de transmisión (TCP) o el Protocolo de datagrama de usuario (UDP) del IP original. Este modo sólo se puede utilizar cuando los pares son puntos extremos de la comunicación. El contraste del modo de transporte es el modo del túnel.

Modo de túnel: encapsulación del datagrama IP completo para IPSec. El modo de túnel sirve para proteger datagramas que tienen como origen o destino un sistema que no es IPSec (como en una red privada virtual VNP). 
