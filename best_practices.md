##Mejores practicas de seguridad en una red de computadores

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
  

    

