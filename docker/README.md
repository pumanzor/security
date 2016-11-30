##Que es Docker?

Docker es una tecnologia que permite ejecutar aplicaciones de software aisladas dentro de contenedores.

###Que es un contenedor?

Un contenedor incluye la aplicacion de software y todas sus dependencias PERO comparte el kernel con otros contenedores, y se ejecutan como procesos aislados en el espacio de usuario en el sistema operativo anfitrion. 

Los contenedores Docker no están ligados a ninguna infraestructura específica: se ejecutan en cualquier computadora, en cualquier infraestructura y en cualquier nube.

###Maquina Virtual

Las máquinas virtuales incluyen la aplicación, los binarios, bibliotecas necesarios, y todo un sistema operativo invitado que puede llegar a decenas de GB.

###Comparacion entre una VM y un contendor docker.

Los contenedores y las máquinas virtuales tienen beneficios similares de aislamiento y asignación de recursos, pero un enfoque arquitectónico diferente permite a los contenedores ser más portátiles y eficientes.

![alt tag](https://github.com/pumanzor/security/blob/master/docker/img/docker.png)


###Instalacion en Debian 8 Jessie

####Pre-requisitos

Docker requiere un S.O. de 64 bits independientemente de la versión de Debian. Además, el kernel debe ser como mínimo version 3.10 o superior.

Primer paso actualizar indice de repositorios e instalar dependencias

- apt-get update
- apt-get install apt-transport-https ca-certificates
- apt-key adv --keyserver hkp://p80.pool.sks-keyservers.net:80 --recv-keys 58118E89F3A912897C070ADBF76221572C52609D

Crear dentro de source.list.d el archivo docker.list apuntando al repo de docker oficial con la version jessie (si disponemos de wheezy cambiarlo por este codigo).

- touch /etc/apt/sources.list.d/docker.list
- vi /etc/apt/sources.list.d/docker.list

agregar esta linea en docker.list

deb https://apt.dockerproject.org/repo debian-jessie main

Actualizar nuevamente el indice de packetes de software e instalar docker

- apt-get update
- apt-get install docker-engine

service docker start

Para comprobar que la instalacion quedo bien, ejecutar
 
- docker run hello-world

Este comando descarga una imagen de prueba y la ejecuta en un contenedor. Cuando el contenedor se ejecuta, imprime un mensaje informativo y luego termina

###Networking

En forma predeterminada docker crea 3 tipos de redes en la maquina host tras la instalacion

> docker network ls

  NETWORK ID          NAME                DRIVER              SCOPE
  c1f8fd284dc9        bridge              bridge              local               
  8969a2bc6879        host                host                local               
  dcbcd42731d4        none                null                local 
 
Cada network driver tiene sus propias caracteristicas, que se explican a continuacion:

###Host Network

Host network añade un contenedor en la pila de red del host de la máquina. Imagine que los contenedores se ejecutan en la misma interfaz de red de la máquina host. Posee las siguientes características:

- Las interfaces de red del contenedor serán idénticas al host de la máquina.
- Sólo una red de host por máquina anfitriona. No se pueden crear más.
- Debe especificar explícitamente "--net = host" en la línea de comandos "docker run" para asignar un contenedor a esta red
- Container linking, “--link mysql-container:mysql” no soportado
- Port mapping, “-p 3307:3306” no soportado.

Ejemplo , crear un contenedor con --net=host

docker run -d --name=mysqltest --net=host --env="MYSQL_ROOT_PASSWORD=mypassword" -v /storage/datadir:/var/lib/mysql mysql

Ahora, nuestra arquitectura de contenedor puede ser ilustrada de la siguiente forma:

![alt tag](https://github.com/pumanzor/security/blob/master/docker/img/image01.png)



###Bridge network

Bridging permite que múltiples redes se comuniquen de forma independiente mientras se mantienen separadas en el mismo host físico. Imagine que esto es similar a otra red interna dentro de la máquina host. 

Sólo los contenedores de la misma red se pueden comunicar entre si , incluyendo la máquina host. Si la máquina anfitriona puede llegar al mundo exterior, también lo pueden hacer los contenedores.

Hay 2 tipos de bridge networks:

    Default bridge (docker0)
    User-defined bridge

Default bridge (docker0)

La red default bridge docker0 es creada automáticamente por Docker durante la instalación. Se puede verificar esto utilizando el comando "ifconfig" o "ip a". El rango de IP predeterminado es 172.17.0.1/16 y se puede cambiar dentro de /etc/default/docker (Debian) o /etc/sysconfig/docker (RedHat). Consulte la documentación de Docker si desea cambiar esto.

Por ejemplo. si no especifica explícitamente el parámetro "--net" en el comando "docker run", Docker creará el contenedor bajo la red docker0 predeterminada:

> docker run --name=mysql-bridge -p 3307:3306 -e MYSQL_ROOT_PASSWORD=mypassword -v /srv/storage/datadir:/var/lib/mysql -d mysql

De forma predeterminada, Docker utiliza iptables para gestionar el reenvío de paquetes al bridge. Cada conexión saliente parecerá originarse de una de las direcciones IP propias de la máquina host. A continuación se muestran las cadenas NAT de la máquina después de que se inició el contenedor anterior:

 [machine-host]$ iptables -L -n -t nat
 Chain POSTROUTING (policy ACCEPT)
 target     prot opt source               destination
 MASQUERADE  all  --  172.17.0.0/16        0.0.0.0/0
 MASQUERADE  tcp  --  172.17.0.2           172.17.0.2           tcp dpt:3306
 
 Chain DOCKER (2 references)
 target     prot opt source               destination
 DNAT       tcp  --  0.0.0.0/0            0.0.0.0/0            tcp dpt:3307 to:172.17.0.2:3306

En este punto, la arquitectura quedaria

![alt tag](https://github.com/pumanzor/security/blob/master/docker/img/image03.png)

###DataStorage

Hay varias maneras de almacenar datos utilizados por MySQL que se ejecutan en contenedores Docker. Docker puede gestionar el almacenamiento de los datos de su base de datos escribiendo los archivos en disco en el sistema host o utilizando su propia gestión interna de volumenes. Si ejecuta el comando inspect, observe la directiva "Volumes" y observe por defecto que el directorio de datos de MySQL (/var/lib/mysql) está montado en el volumen interno de Docker.

La otra forma es crear un directorio de datos en el sistema host (fuera del contenedor) y montarlo en un directorio visible desde el interior del contenedor. Esto coloca los archivos de base de datos en una ubicación conocida en el sistema host y facilita que las herramientas y las aplicaciones del sistema host accedan a los archivos. La desventaja es que el usuario necesita asegurarse de que el directorio existe, y que por ejemplo permisos de directorio y otros mecanismos de seguridad en el sistema host esten configurados correctamente.

Cree un directorio de datos de un volumen en el lado del host:

> mkdir -p /srv/datastorage/mysql/data

> mkdir -p /srv/datastorage/mysql/conf

> docker run -d --name=test-mysql --env="MYSQL_ROOT_PASSWORD=clave" -p 6603:3306 -v /srv/datastorage/mysql/conf:/etc/mysql/conf.d -v /srv/datastorage/mysql/data:/var/lib/mysql mysql


![alt tag](https://github.com/pumanzor/security/blob/master/docker/img/image00.png)


###Docker File System

Para entender los volúmenes de Docker, es importante entender primero cómo funciona el sistema de archivos Docker.

Una imagen Docker es una colección de layers o capas en modo sólo lectura. Cuando se inicia un contenedor desde una imagen, Docker añade una capa de lectura y escritura a la parte superior de esa pila de capas de sólo lectura. Docker llama a esto UFS.

Cada vez que se cambia un archivo, Docker hace una copia del archivo desde las capas de sólo lectura hasta la capa superior de lectura y escritura. Esto deja el archivo original (solo lectura) sin cambios.

Cuando se elimina un contenedor, se pierde la capa superior de lectura y escritura. Esto significa que los cambios realizados después de que el contenedor se inició se han ido.

Un volumen permite que los datos persistan, incluso cuando se elimina un contenedor. Los volúmenes son también una manera conveniente de compartir datos entre el host y el contenedor.

Montar un volumen es una buena solución si desea:

- Empujar datos a un contenedor.(PUSH)
- Extraer datos de un contenedor. (PULL)
- Compartir datos entre contenedores.

Los volumenes Docker existen fuera de las capas RW y RO del UFS  (Union File System). El volumen es una carpeta que es compartida entre el contenedor y la maquina host. Los volumenes pueden ser compartidos entre contenedores.

Un volumen Docker vive fuera de un contenedor, es decir en la maquina host (maquina anfitriona).

Desde el contenedor, el volumen actúa como una carpeta que puede utilizar para almacenar y recuperar datos. Es simplemente un punto de montaje para un directorio en el host.

Hay varias maneras de crear y administrar volúmenes de Docker. Cada método tiene sus propias ventajas y desventajas.

###Usando el comando "docker volume create"

El comando "volume create" creara un volumen con nombre. El nombre permitira localizar y asignar facilmente los volumenes de Docker en los contenedores

Para crear un volumen, utilice el comando:

docker volume create --name [nombre del volumen]

Por ejemplo, para crear un volumen denominado datavolumen, el comando es:

docker volume create --name datavolume

###Iniciar un contenedor con un volumen

To launch a container which will use a volume you have created with docker volume create, add the following argument to the docker run command:

Para iniciar un contenedor que utilice un volumen que se haya creado con el comando volume create, agregue el siguiente argumento al comando docker run:

> -v [volume name]:[container directory] 

For example, to run a container from the centos image named my-volume-test and map the volume data-volume to the container's /data directory, the command is:

Por ejemplo, para ejecutar un contenedor con el nombre "vol-test" desde la imagen centos y asignarle el volumen "data-volume"  al directorio /data del contenedor, el comando es:

docker run -itd --name vol-test -v data-volume:/data centos /bin/bash

###Listar Volumes

Para listar todos los volumen docker dentro de un sistema, use el comando:

> docker volume ls

Lo anterior retornara una lista de todos los volumenes docker que han sido creados en el host.



###Inspeccionar un volumen

Para inspeccionar un volumen con nombre, utilice el comando:

docker volume inspect [volume name]

Lo anterior retornara informacion acerca del volumen, incluyendo su punto de montaje (el directorio donde "vive") en el sistema host.

Por ejemplo, para obtener más información sobre el volumen de datos que creamos anteriormente, el comando es:

> docker volume inspect data-volume


###Remover un Volume

Para remover un volumen con nombre, use el comando:

> docker volume rm [volume name]

No podrá eliminar un volumen si está siendo utilizado por un contenedor existente. Antes de quitar el volumen, tendrá que detener y eliminar el contenedor con los comandos:

> docker stop [container name or ID]

> docker rm [container name or ID]

Por ejemplo, para eliminar el volumen "datavolume", primero necesitaremos detener y elimimar el contenedor "container-test" el cual esta usando el volumen: 

> docker stop container-test

> docker rm container-test

Entonces el volumen "datavolume" puede ser eliminado con:

> docker volume rm datavolume

------------------

###Comandos Basicos

Ver o listar todas las imagenes instaladas

> docker images --all

Ver o listar todos los contenedores instalados (ejecutandose o no)

> docker ps -a

Crear un contenedor y ejecutarlo

docker run -it --name webapp php:5.6-apache -p81:80 /bin/bash

    run - Run a command in a new container.
    --name - Give a name to the container. If you don’t specify this, Docker will generate a random name.
    php:5.6-apache  - The image name as stated on the Docker Hub page
 
Bajar una imagen
 
 docker pull mysql
 
 
> docker ps -a
 
 Under the ‘STATUS’ column, you can see the status was “Exited (1) 6 minutes ago”. If a program ended while returning a non-zero value, it means that the program was terminated with some kind of error. So, what happened? The MySQL image was successfully downloaded but Docker failed to run it as container because the environment is not properly set up. This is stated in the error lines.
 
 
para ver logs y registros ejecutar

> docker logs test-mysql

Detener la ejecucion de un contenedor

> docker stop CONT_ID or NAME_CONT

Iniciar un contenedor

> docker start CONT_ID or NAME_CONT

Eliminar un contenedor

> docker rm CONT_ID

Eliminar una imagen

> docker rmi IMAGE_ID

Eliminar todas las imagenes

> docker rmi $(docker images -q)
 
Para obtener la direccion ip del contenedor ejecutar

> docker inspect test-mysql |grep IPAddress

Para saber el rango que me asigno en la tarjeta de red de la maquina fisica ejecutar:

> ip a | grep docker | grep inet

cada vez que se reinicia un contenedor, docker asigna en forma dinamica la direccion ip del contenedor

- docker stop NAME_CONTE
- docker start NAME_CONTE
- docker inspect NAME_CONTE |grep IPAddress
 -       "IPAddress": "172.17.X.Y",



 
 
 
##DOcker UI
 
 
 docker run -d -p 9000:9000 --name dockerui --privileged -v /var/run/docker.sock:/var/run/docker.sock kevan/dockerui
 
 
 
 -
----trash-------------------

mkdir /webdata
sudo docker run -it --name webapp3 -v /webdata:/var/www/html php:5.6-apache /bin/bash

- docker rm test-mysql
- docker run --name=test-mysql --env="MYSQL_ROOT_PASSWORD=mypassword" mysql 

