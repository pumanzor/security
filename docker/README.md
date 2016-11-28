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



###Bridge network

Bridging permite que múltiples redes se comuniquen de forma independiente mientras se mantienen separadas en el mismo host físico. Imagine que esto es similar a otra red interna dentro de la máquina host. 

Sólo los contenedores de la misma red se pueden comunicar entre si , incluyendo la máquina host. Si la máquina anfitriona puede llegar al mundo exterior, también lo pueden hacer los contenedores.

Hay 2 tipos de bridge networks:

    Default bridge (docker0)
    User-defined bridge

Default bridge (docker0)

La red default bridge docker0 es creada automáticamente por Docker durante la instalación. Se puede verificar esto utilizando el comando "ifconfig" o "ip a". El rango de IP predeterminado es 172.17.0.1/16 y se puede cambiar dentro de /etc/default/docker (Debian) o /etc/sysconfig/docker (RedHat). Consulte la documentación de Docker si desea cambiar esto.

Por ejemplo. si no especifica explícitamente el parámetro "--net" en el comando "docker run", Docker creará el contenedor bajo la red docker0 predeterminada:

> docker run \
  --name=mysql-bridge \
  -p 3307:3306 \
  -e MYSQL_ROOT_PASSWORD=mypassword \
  -v /srv/storage/datadir:/var/lib/mysql \
  -d mysql


comandos Basicos

Ver o listar todas las imagenes instaladas

> docker images --all

Ver o listar todos los contenedores instalados (ejecutandose o no)

> docker ps -a
 
docker run --name=test-mysql mysql

    run - Run a command in a new container.
    --name - Give a name to the container. If you don’t specify this, Docker will generate a random name.
    mysql - The image name as stated on the Docker Hub page
 
 o tambien
 
 docker pull mysql
 
 por ejemplo da un error verificar con
 
 docker ps -a
 
 Under the ‘STATUS’ column, you can see the status was “Exited (1) 6 minutes ago”. If a program ended while returning a non-zero value, it means that the program was terminated with some kind of error. So, what happened? The MySQL image was successfully downloaded but Docker failed to run it as container because the environment is not properly set up. This is stated in the error lines.
 
 
- docker rm test-mysql
- docker run --name=test-mysql --env="MYSQL_ROOT_PASSWORD=mypassword" mysql 

enviara todo por pantalla ya que esta en modo foreground, para enviarlo a bg ejecutar con detach mode

docker run --detach --name=test-mysql --env="MYSQL_ROOT_PASSWORD=mypassword" mysql

para ver los ejecutar

docker logs test-mysql

entonces desde la maquina fisica me puede conectar con el cliente mysql, mysql -uroot -p -h 172.17.xx

para obtener la direccion ip del contenedor ejecutar

docker inspect test-mysql |grep IPAddress

para saber el rango que me asigno en la tarjeta de red de la maquina fisica ejecutar:

ip a | grep docker | grep inet

cada vez que se reinicia un contenedor, docker asgian en forma dinamica la direccion ip del contenedor

- docker stop test-mysql
- docker start test-mysql
- docker inspect test-mysql |grep IPAddress
 -       "IPAddress": "172.17.0.4",


Our IP address just changed to 172.17.0.21. If you had an application that connects to this container via the old IP address, the application would not get connected anymore. Docker introduces another way to link your container with another container, to ensure whatever IP address assigned to it will get updated in the linked container. Let’s say we deploy a Wordpress application (which has no MySQL installed on that image), and want to link with our existing MySQL container, test-mysql. Here is what you should do:



 
 --------------

docker pull mysql

docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name servermysql --publish 3306:3306 -d mysql

docker exec -it mysql bash

apt-get update

apt-get install vim nano

crear db y crear tabla


docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name mimysql --publish 3306:3306 -d okservermysql


-------------------

mkdir /webdata
sudo docker run -it --name webapp3 -v /webdata:/var/www/html php:5.6-apache /bin/bash

