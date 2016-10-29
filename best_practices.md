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

La conexión de dispositivos personales sólo se permitirá en las redes o segmentos de red que contienen absolutamente ninguna información sensible de la organizacion.

Los dispositivos personales tales como teléfonos inteligentes, tablets, memorias USB son realmente difíciles de controlar para una organización en el sentido de que los propios usuarios tienen que  determinar el nivel de seguridad que poseen sus dispositivos.

Las medidas de seguridad en una organización o empresa, por lo tanto, no pueden por su propia naturaleza, ser aplicados a este tipo de dispositivos. De todas formas existen aplicaciones propietarias que se pueden instalar en smartphone de manera de ser integrados al sistema de seguridad de la organizacion y ser conscientes de que estan conectados y autorizados para ingresar a la red.

Esta regla es frecuentemente percibida como una restricción inaceptable e incluso retrógrada por un gran número de usuarios. Sin embargo, a menos que esto se cumpla, la tarea de un hacker se hace  mucho más fácil. 

De hecho, por cada cien dispositivos personales conectados a la red de una empresa, se ha estimado que estadísticamente al menos diez de ellos han sido comprometidos por malware genérico (dejando a un lado los ataques dirigidos).

Por lo tanto, es importante prohibir o prevenir el acceso a la red y a los sistemas de informacion. Esta prohibicion debe aplicarse en primer lugar a un nivel organizacional, incluso si no hay reglas tecnicas para prevenirlas, los usuarios deberian adoptar este tipo de practicas, por ejemplo a traves de una carta que determine el uso de los recursos de TI.

En la mayor medida posible, esta prohibicion debe ser complementada por medidas tecnicas, sin embargo a veces puede resultar dificil de implementar (ej, control sistematico de acceso a la red, la desactivacion de los puertos USB).

Donde hay una necesidad de trabajar en forma remota, la organizacion debe proporcionar la medios profesionales para permitir este tipo de uso. La transferencia de email desde cuentas de correos institucionales hacia cuentas personales, sin embargo, debe ser explicitamente prohibido.

###Actualizacion de software

Diariamente, las vulnerabilidades se revelan en un gran numero de paquetes de software ampliamente utilizado.

A veces solo unas pocas horas son suficientes para que el malware explote estas vulnerabilidades para comenzar a circular sobre Internet. Por eso es muy importante priorizar el uso de tecnologias establecidas, para lo cual se garantiza el soporte; para evitar tecnologias que su equipo de TI no es totalmente competente. 

####6.- Conocer los procedimientos de cómo se actualizan todos los componentes de software y mantenerse al día sobre las vulnerabilidades de estos componentes y sus actualizaciones necesarias.

Es crucial determinar cómo los componentes de software utilizados por la organizacion deben ser actualizados. Si un componente de software no se puede actualizar, no debe ser utilizado (véase el pto 7. la forma de gestionar las excepciones en este sentido).

Además, las actualizaciones de software sólo deben ser descargados desde sitios de confianza (por lo general desde sitios del fabricante)

####7.- Definir y aplicar estrictamente una política de actualización.

Esta política debe incluir:
  - Los items a ser actualizados.
  - Las responsabilidades de los diferentes actores en el proceso de actualización;
  - Los medios utilizados para obtener y evaluar los cambios.

A tener en cuentos los siguientes puntos:

  - Una herramienta dedicada debe ser usada, como por ejemplo WSUS para entornos microsoft que permite gestionar cambios a aplicar de manera uniforme en todo el parque informatico.
  
Teniendo en cuenta el articulo 6, es vital que ningun equipo pc, computador o componente de la red sea excluido de la politica de actualizacion.

Desafortunadamente, sin embargo , el departamento de TI frecuentemente mantiene sistemas obsoletos que ya no son soportados por lo fabricantes y por lo cual no se dispone de parches o actualizaciones, estos sistemas obsoletos son ciertas aplicaciones que se usan de forma diaria y que lamentablemente forman parte de la cadena de operacion. En este caso es vital que dichos sistemas sean aislados:

  - A nivel de red, usando un filtro muy estricta que sólo autorize el acceso a las aplicaciones necesarias.
  - En el ámbito de la autenticación, asegurar que no haya ninguna contraseña (ya sea para el sistema o para el software) sea compartida con el resto de los sistemas de información.
  - En el ámbito de aplicación, asegurando que estos sistemas no utilizan recursos compartido con el resto de los sistemas de información

###Autenticacion de usuarios.

Las contraseñas son a menudo el talón de Aquiles de los sistemas de información. De hecho, aunque las organizaciones a menudo formular una política de contraseñas, sólo en raras ocasiones se aplica esta manera uniforme en todo el parque informático.

####8.- Identificar a cada individuo cuando acceda a los sistemas por su nombre

Esta norma tiene por objeto eliminar cuentas genéricas, anonimas; la idea es que sea más fácil atribuir una acción en los sistemas relacionado con un individuo específico. Esto es especialmente útil en el caso de un incidente.

Por supuesto, esta regla no le impide retener cuentas técnicas (denominado cuentas de servicio) que no se atribuyen a un individuo específico.

####9.- Establecer reglas para la eleccion y tamaño de las contraseñas.

Un listado de buenas practicas para la seleccion y tamaño de las contraseñas se pueden encontrar en el siguiente link []

De estas reglas, las mas criticas son hacer que los usuarios tengan conciencia de los riesgos involucrados en la eleccion de claves que sean demasiado facil de adivinar y los riesgos de volver a utilizar la misma contraseña, especialmente para cuentas de email personales e institucionales.

####10.- Puesta en marcha de metodos tecnicos que permitan normas de autenticacion a seguir.

Los siguientes métodos permiten reglas de autenticación y contraseñsa que se deben seguir:

  - Bloqueo de cuentas cada 6 meses hasta que la contraseña ha sido cambiada;
  - Bloqueo de cualquier configuración de una máquina que permite la puesta en marcha en modo "inicio de sesión automático" (es decir, sin una contraseña) o desde una cuenta de invitado.
  - Verificar que las contraseñas elegidas no son fáciles de resolver.
  
####11.- No almacene contraseñas a la vista en archivos o dentro de los sistemas de informacion.

Para simplificar las cosas, los usuarios y los administradores frecuentemente suelen escribir sus contraseñas a la vista en los archivos almacenados en sus ordenadores o se envian a sí mismos a través de correo electrónico. Estas practicas deben ser prohibidas. 

Claves e información secreta almacenada en maquinas de usuarios son la primera cosa que los hackers buscarán y utilizaran.

Es también importante no utilizar los mecanismos automáticos de almacenamiento de la contraseña (por ejemplo, el botón de un navegador "siempre recordar contraseña"). 

Si existe un gran número de contraseñas que obligan a usar una solución de almacenamiento centralizada, un sistema cuya seguridad ha sido validado debe ser utilizado para tal fin.

####12.- Sistemáticamente cambiar la configuración de autenticación predeterminada (contraseña, certificados)
en los dispositivos de red (switches, routers, servidores, impresoras).

Las configuraciones por default se conocen de forma sistematica por los atacantes, por lo general son bastantes triviales;  ejemplo clave igual al nombre de usuario, claves compartida por varios dispositivos en el mismo rango, etc).

###SECURE COMPUTER TERMINALS
