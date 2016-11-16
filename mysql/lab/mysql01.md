##Lab 1 _ Gestor base de datos MYSQL

###1.- Instalar Mysql en Linux

apt-get install mysql-server

en el momento de la instalación va a solicitar la clave de administrador de mysql

con esta clave era posible gestionar cualquier acción dentro de mysql, eliminar, crear, modificar bases de datos tablas, crear/eliminar usuarios, etc

###2.- Verificar donde queda instalado por default los archivos del server y los archivos de configuración

/etc/mysql
/var/lib/mysql

###3.- Crear una base de datos desde línea de comando
Primero conectar con el cliente mysql
Mysql -uroot -p
mysql> create database cursociber;

###4.- Creamos el usuario “usuariox” para conectar al server desde localhost usando el password clave
grant usage on *.* to usuariox@localhost identified by ‘clave’;
5.- creamos los privilegios en cusociber.* para el usuario “usuariox”
mysql> grant all privileges on cursociber.* to usuario@localhost ;

###6.- listar todos los usuarios;

select user from mysql.user;

###7.- revocar privilegios de un usuario

REVOKE ALL PRIVILEGES on cursociber.* from usuariox@localhost;

###8.- que sucede si alguien revoca todos los privilegios para el usuario root o peor aun cambia la clave del administrador?

restaurar la clave de root

systemctl stop mysql
mysqld_safe --skip-grant-tables &

mysql -u root
mysql> use mysql;
mysql> update user set password=PASSWORD("nuevaclave") where User='root';
mysql> flush privileges;
mysql> quit.

kill -9 PID PID2

systemctl start mysql

mysql -uroot -p

####restaurar todos los privilegios

systemctl stop mysql
mysqld_safe --skip-grant-tables &
mysql -uroot
update mysql.user set grant_priv = 'Y' where user = 'root'; commit; flush privileges;
 GRANT ALL ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
flush privileges;
quit;

kill -9 PID PID2

systemctl start mysql

mysql -uroot -p




