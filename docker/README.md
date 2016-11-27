##Que es Docker?

Docker es una tecnologia que permite ejecutar aplicaciones de software aisladas dentro de contenedores.

###Que es un contenedor?

Un contenedor incluye la aplicacion de software y todas sus dependencias PERO comparte el kernel con otros contenedores, y se ejecutan como procesos aislados en el espacio de usuario en el sistema operativo anfitrion. 

Los contenedores Docker no están ligados a ninguna infraestructura específica: se ejecutan en cualquier computadora, en cualquier infraestructura y en cualquier nube.

###Maquina Virtual

Las máquinas virtuales incluyen la aplicación, los binarios, bibliotecas necesarios, y todo un sistema operativo invitado que puede llegar a decenas de GB.

###Comparacion entre un contendor docker y una VM.





###Instalacion en Debian 8 Jessie

####Pre-requisitos

Docker requiere un S.O. de 64 bits independientemente de la versión de Debian. Además, el kernel debe ser como mínimo version 3.10 o superior.

- apt-get update
- apt-get install apt-transport-https ca-certificates
- apt-key adv --keyserver hkp://p80.pool.sks-keyservers.net:80 --recv-keys 58118E89F3A912897C070ADBF76221572C52609D

- touch /etc/apt/sources.list.d/docker.list
- vi /etc/apt/sources.list.d/docker.list

agregar esta linea en docker.list

deb https://apt.dockerproject.org/repo debian-jessie main

- apt-get update
- apt-cache policy docker-engine
- apt-get install docker-engine
 
service docker start

Para comprobar que la instalacion quedo bien, ejecutar
 
- docker run hello-world

Este comando descarga una imagen de prueba y la ejecuta en un contenedor. Cuando el contenedor se ejecuta, imprime un mensaje informativo y luego termina

###Comandos Basicos

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

