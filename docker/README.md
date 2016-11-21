

docker pull mysql

docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name mysql --publish 3306:3306 -d mysql

docker exec -it mysql bash

apt-get update

apt-get install vim nano

crear db y crear tabla


docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name mimysql --publish 3306:3306 -d okservermysql

