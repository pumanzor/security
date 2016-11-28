1.- Crear un volumen de datos compartido entre varios contenedores docker mediaente una aplicacion web, para ello mapear el 
servicio http en puertos distintos o en Ip distintas, para ello utilice las diferentes opciones de configuracion de docker,

Guia de Lab.

- crear una carpeta donde se almacenaran los datos a compartir en la maquina host (anfitrion)
- instalar un contenedor con apache y php
  - docker run -it --name webapp -v /webdata:/var/www/html php:5.6-apache /bin/bash

- actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- crear otro contenedor apuntando al mismo directorio compartido
  - docker run -it --name webapp2 -v /webdata:/var/www/html php:5.6-apache /bin/bash
- actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- 
