##Laboratorio Docker - Guia 1

###1.- Crear un volumen de datos compartido entre varios contenedores docker utilizando como servicio una aplicacion web, para ello mapear el http en puertos distintos o en direcciones IPv4 distintas, para ello use las diferentes opciones de configuracion de docker.

- crear una carpeta donde se almacenaran los datos a compartir en la maquina host (anfitrion)
- instalar un contenedor con apache y php
  - docker run -it --name webapp -v /webdata:/var/www/html php:5.6-apache -p81:80 /bin/bash

- actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- crear otro contenedor apuntando al mismo directorio compartido
  - docker run -it --name webapp2 -v /webdata:/var/www/html php:5.6-apache -p82:80 /bin/bash
- actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- Realice pruebas de escritura en la carpeta /srv/webdata y verifique que lo anterior se refleja en los 2 contenedores.
- Realice lo anterior pero utilizando --net=host


###2.- Construir una imagen de Docker: el objetivo de este punto es crear un contenedor, instalar y configurar algunas aplicaciones utiles dentro del mismo, exportarlo y luego importarlo en otra maquina
