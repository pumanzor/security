## Laboratorio Docker - Guia 1

1.- Crear un volumen de datos compartido entre varios contenedores docker utilizando como servicio una aplicacion web, para ello mapear el http en puertos distintos o en direcciones IPv4 distintas, use las diferentes opciones de configuracion de docker a nivel de networking.


- Crear una carpeta donde se almacenaran los datos a compartir en la maquina host (anfitrion)
- Instalar un contenedor con apache y php
  - docker run -it --name webapp -v /srv/webdata:/usr/local/apache2/htdocs -p81:80 httpd /bin/bash

- Actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- Crear otro contenedor apuntando al mismo directorio compartido
  - docker run -itd --name webapp2 -v /srv/webdata:/usr/local/apache2/htdocs -p82:80 httpd /bin/bash
- Actualizar el indice de repositorios e instalar algunas herramientas utiles, nano, vi, net-tools
- Realice pruebas de escritura en la carpeta /srv/webdata y verifique que lo anterior se refleja en los 2 contenedores.
- Realice lo anterior pero utilizando la opcion --net=host

Preg. en que situaciones ud utilizaria la opcion de puertos distintos y direcciones ipv4 distintas?


2.- Construir una imagen de Docker: el objetivo de este punto es crear un contenedor, instalar y configurar algunas aplicaciones utiles dentro del mismo y luego cargar esta imagen en otra maquina con docker.

- Seleccione algun contenedor de su interes para este punto, puede seleccionarlo desde

  - http://hub.docker.com , ejemplo httpd
  
- Instale http desde consola

  - docker pull httpd
  - docker run -it --name webapp httpd /bin/bash

  - inspeccione el contenedor con ifconfig, verifique donde se encuentran los archivos de apache2
  - actualice el repositorio
  - instale algun editor de texto
  - escriba algunos datos en el directorio root
    - touch abc
    - touch 123456
  - salir y verifique el id del container
    - docker ps -a

Luego exporte el contenedor

  - docker export CONT_ID | gzip > web1.tar.gz
  
- Enviela a su compañero via scp

- Inicie el contenedor en el PC destino

  - zcat web1.tar.gz | docker import - web1
  - docker run -it --name webapp  web1 /bin/bash
  
- Verifique que los datos creados anteriormente persisten.

- Realice el ejercicio anterior pero con el comando "save"

  -En primer lugar instale una imagen liviana, ejemplo busybox
  
  - docker pull busybox
  - docker run -it --name test1 busybox /bin/sh
  
  - luego crear algunos archivos dentro del contenedor con el comando touch o instale alguna aplicacion co apt-get
  - touch 1234; touch a; touch b; touch c;
  
  
   luego hacer commit con los cambios realizados en el container
  - exit 
  - docker commit CONTAINER_ID busytest
  
  luego verifique q se haya creado la imagen "busytest"
  
  - docker images --all
  
  Para que los datos persistan en la imagen utilice el comando save y posteriormente envialo via scp al equipo de su compañero
  
  - docker save busytest > imagensave.tar
  - scp imagensave.tar usuario_dest@IP:/home/usuario_dest

  en el equipo destino levante la imagen guardad
  
  - docker load < imagensave.tar
  
  por ultimo ejecute el contenedor utilizando a imagen restaurada.
  
  - docker run -it --name imagen busytest sh

- Que diferencias existen entre utilizar save y export?

- Que otras funcionalidades u opciones ud podria aplicar en el caso de contenedores que se exportan localmente o en el sitio de docker.com?


#### Informe de Lab docker debe incluir las respuestas a la guia

