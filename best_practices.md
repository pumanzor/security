##Mejores practicas de seguridad en una red de computadores

###Conocer acerca de su sistemas de informacion y sus usuarios.

Conocer su sistema de información es un requisito previo e importante para hacerlo seguro. De hecho, si su sistema de información incluyen equipos que se omiten de los inventarios regulares, este equipo se convertirá en obsoleto rápidamente y será un objetivo para un atacante

####1.- Tener un mapa de la arquitectura de red actualizado y lo mas preciso posible

La preparacion de un mapa de la arquitectura de red es el primer paso para adquirir un mayor y extensivo conocimiento 
de los sistemas de informacion. Esto hara que sea mas facil idear medidas de seguridad que se adaptaran y se ajustaran a los sistemas instalados y garantizara que ningún elemento se pase por alto en la aplicación de una medida de seguridad y para facilitar una respuesta en el caso de un incidente

Este mapa debe incluir, como mínimo, los siguientes elementos:

  - Una lista de todos los equipos (PC usuario y servidores) indicando modelo y software utilizado. Obviamente, esta lista debe ser lo más precisa posible. Como punto de partida para este proceso, es posible que desee crear una lista de las máquinas utilizadas indicando:
   
    - Direccion IP y MAC address
    - Software utilizado y sus correspondientes versiones

  - La arquitectura de red, la identificacion de todos los puntos de conexion, accesos Internet, switches, servidores de backup
  storages, access point y otros sistemas que cuentan con direccionamiento. Una vez realizado este mapa debe ser actualizado con los roles y servicios que cada uno prestan.
  
> Este mapa no se debe almacenar en la red que representa, ya que este es uno de los elementos que un pirata informático buscará  en primer lugar en el caso de éxito de intrusión
  
Ahora realizar todo lo anterior no es tarea facil de ejecutar si nos encontramos con una red informatica ya montada y de tiempo funcionando y operando. Para estos casos lo ideal es apoyarse en algun software de inventario de red que nos pueda sistematizar la recogida de informacion.

Paralelamente es muy util activar las opciones de administracion remotos de todos los equipos que la soporten, es el caso del protocolo SNMP el cual nos permitira conocer ademas de lo anterior, otros parametros y variables en el tiempo de estos equipos.

Tambien en lo posible disponer de un servidor syslog en donde se vayan reportando las acciones configuradas en los dispositivos de red que lo soporten.

####2.- Mantener un inventario exhaustivo de las cuentas con privilegios y garantizar que esto se actualiza

- Como mínimo, es importante tener una lista de:

  - Los usuarios con una cuenta de administrador (o con privilegios superiores a los de un usuario estándar) en el sistema de información.
  - Los usuarios con privilegios suficientes para acceder a los directorios de trabajo de los administradores o, en particular, de todos los usuarios;
  - Los usuarios con una máquina que no es administrado por el departamento de TI y por lo tanto no se gestiona de acuerdo con las politicas de seguridad de la organizacion. (ejemplo, un equipo que no se encuentra dentro del dominio por lo tanto no cuenta con actualizaciones de AV, parches, actualizaciones, etc)
  
> Esta lista debe mantenerse actualizada.

También es importante contar con una lista de usuarios con privilegios suficientes para leer los mensajes de correo electrónico de gestión de la empresa o particular de todos los usuarios. 

Sin embargo, la compilación de una lista de las personas que en realidad tienen acceso a esta información puede ser a veces extremadamente difícil. Si dicha lista no se puede compilar de forma fiable, se necesita un registro de acceso al buzón que se creará y la lista de los usuarios que acudieron a los buzones más sensibles verificandolo periódicamente.

En un sistema Windows, la mayor parte de esta información se puede obtener mediante el análisis de la configuración de Active Directory.

También es muy recomendable que utilice una nomenclatura clara para el nombre de la cuenta (cuentas de administradores con algun prefijo como ADM, cuentas con el prefijo SRV indicando que se trata de servicios, etc)
  
####3.- Crear y aplicar procedimientos para la llegada y salida de los usuarios (personal, pasantes, etc.)


Estos procedimientos tienen por objeto garantizar que los derechos concedidos en el sistema de información se aplicó la forma más racional posible. Es particularmente importante que todos los derechos asignados a un individuo son revocado cuando se van. 

Los procedimientos deben como mínimo establecer:

  - gestión (creación / eliminación) de cuentas TI  (y sus correspondientes buzones) y la asignación de los derechos asociados a estas cuentas en el sistema de información, incluyendo los usuarios externos y proveedores de servicios.

  - gestión de acceso a las dependencias (en particular, la recepción y la devolución de tarjetas magnéticas a las instalaciones);

  - gestión de los equipos portátiles

  - gestión de documentos sensibles (posesión, todas las autorizaciones la eliminación de los locales);

  - gestión del control de las autorizaciones de personal.

Es importante que los cambios de personal se gestionen debidamente y a tiempo, sobre todo los usuarios que vayan dejando la organizacion o los de paso transitorio.

Los privilegios asociados a determinadas cuentas de usuario a menudo aumentan con los movimientos internos, que dan lugar a la asignación de nuevos derechos sin borrar los que ya no se aplican.

###Control de la Red.

####4.- Limitar el número de puntos de acceso a Internet a sistemas y usuarios que sean extrictamente necesarios.

Usted debe ser capaz de identificar con precisión los puntos de acceso a Internet (ADSL, dedicados, etc.) y las interconexiones con redes de asociados, ademas debe limitarlos al mínimo estrictamente necesario para que sea más fácil centralizar y estandarizar la vigilancia del tráfico.

####5.- Prohibir la conexión de dispositivos personales al sistema de información de la organización.

