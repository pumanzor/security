apt-get update
apt-get install apt-transport-https ca-certificates

apt-key adv --keyserver hkp://p80.pool.sks-keyservers.net:80 --recv-keys 58118E89F3A912897C070ADBF7622

/etc/apt/sources.list.d/docker.list

deb https://apt.dockerproject.org/repo debian-jessie main

 apt-get update
 apt-cache policy docker-engine
 apt-get install docker-engine
 
 service docker start
 
  docker run hello-world
  
 ----------------------

docker pull mysql

docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name servermysql --publish 3306:3306 -d mysql

docker exec -it mysql bash

apt-get update

apt-get install vim nano

crear db y crear tabla


docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name mimysql --publish 3306:3306 -d okservermysql

