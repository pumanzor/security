##Laboratorio Docker - Guia 1

1.- Crear un volumen de datos compartido entre varios contenedores docker utilizando como servicio una aplicacion web, para ello mapear el http en puertos distintos o en direcciones IPv4 distintas, use las diferentes opciones de configuracion de docker a nivel de networking.


- Crear una carpeta donde se almacenaran los datos a compartir en la maquina host (anfitrion)
- Instalar un contenedor con apache y php
  - docker run -it --name webapp -v /srv/webdata:/var/www/html php:5.6-apache -p81:80 /bin/bash

- Actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- Crear otro contenedor apuntando al mismo directorio compartido
  - docker run -it --name webapp2 -v /srv/webdata:/var/www/html php:5.6-apache -p82:80 /bin/bash
- Actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- Realice pruebas de escritura en la carpeta /srv/webdata y verifique que lo anterior se refleja en los 2 contenedores.
- Realice lo anterior pero utilizando la opcion --net=host


2.- Construir una imagen de Docker: el objetivo de este punto es crear un contenedor, instalar y configurar algunas aplicaciones utiles dentro del mismo y luego cargar esta imagen en otra maquina con docker.

- Seleccione algun contenedor de su interes para este punto, puede seleccionarlo desde

  - http://hub.docker.com , ejemplo php:5.6-apache
  
- Instale el contenedor con php:5.6-apache desde consola

  - docker run -it --name webapp  php:5.6-apache /bin/bash
  - escriba algunos datos en el directorio inicial,
    - touch abc
    - touch 123456
  - salir y verifique el id del container
    - docker ps -a
Luego exporte el contenedor

  - docker export CONT_ID | gzip > web1.tar.gz
  
- Enviala a su compañero via scp

- Inicie el contenedor en el PC destino

  - zcat web1.gz | docker import - web1
  - docker run -it --name webapp  web1 /bin/bash
  
- Verifique que los datos creados anteriormente persisten.

- Realice el ejercicio anterior pero con el comando "save"

- Que diferencias existen entre utilizar save y export?
