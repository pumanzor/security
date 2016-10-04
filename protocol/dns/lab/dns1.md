##Laboratorio DNS

####Instalar Bind9: apt-get install bind9

####Verificar que el server dns se encuentra listando en el puerto 53/udp

  - Comprobar que otros programas esten usando el mismo puerto ej. dnsmasq

* Configurar un cliente dns que apunte a la direccion ip que se acaba de crear como server
** Comprobar politicas por default de Bind, realizar resoluciones de nombres desde el pc cliente

* Configurar Bind para sirva como dns recursivo cache

** Editar el archivo /etc/bind/named.conf.options y agregar la directiva
*** recursion yes;

