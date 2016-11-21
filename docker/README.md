docker pull mysql

docker run --detach --env MYSQL_ROOT_PASSWORD=456 --name mysql --publish 3306:3306 -d mysql
