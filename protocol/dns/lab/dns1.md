##Laboratorio DNS

####Instalar Bind9: apt-get install bind9

####Verificar que el server dns se encuentra listando en el puerto 53/udp
- Comprobar que otros programas esten usando el mismo puerto ej. dnsmasq
- Para buscar use este comando, ej:  ps -fea|grep dns

####Configurar un cliente dns que apunte a la direccion ip que se acaba de crear como server
- Comprobar politicas por default de Bind.
- Realizar resoluciones de nombres desde el pc cliente
- Porque Bind9 se comporta de esta manera? ver https://github.com/pumanzor/security/blob/master/protocol/dns/recursion.md

####Configurar Bind para sirva como dns recursivo cache
- Editar el archivo /etc/bind/named.conf.options y agregar la directiva

> recursion yes;

- Guarde los cambios y nuevamente realice una resolucion de nombre desde el cliente
- Haga pruebas desde otra red distinta a la que se encuentra el DNS Server, que efecto trae la ultima accion?
- Edite el archivo named.conf.options y agregue las siguientes directivas:}

> allow-recursion { trustip; };

- Edite el archivo named.conf y agregue el listado de ip a permitir hacer consultas

> acl "trustip" {
192.168.126.0/24; 192.168.7.0/24; 192.168.1.0/24; localhost;
};


