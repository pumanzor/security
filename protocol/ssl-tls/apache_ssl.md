##Activar SSL en apache2

* a2nmod ssl
* a2enmod default-ssl
* /etc/init.d/apache2 restart

##Crear certificados

* mkdir –p –v –m 0700 /etc/apache2/ssl
* openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/apache2/ssl/server.key -out /etc/apache2/ssl/server.crt
* chown -R root /etc/apache2/ssl
* chmod -R 400 /etc/apache2/ssl

##Apache HTTPS step by step

###Crear una llave privada

* openssl genrsa -out server1.key 2048

###Crear un CSR (Certificate Signing Request)

Un CSR es la base para un certificado SSL, en el se definen datos como el dominio, organización, ubicación, información de contacto, entre otros.

* openssl req -new -key server1.key -out server1.csr

###Generar el certificado

* openssl x509 -req -days 365 -in server1.csr -signkey server1.key -out server1.crt

