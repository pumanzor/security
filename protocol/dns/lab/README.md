##Laboratorio DNS

###Objetivos:

* Comprender el funcionamiento la resolucion de nombres en Internet utilizando software Bind
* Analizar el flujo de las consultas entre los distintos entes involucrados en el sistema
* Instalar desde 0 un servidor DNS autoritativo, un servidor DNS Recursivo y cache

###Elementos a utilizar

* Computador con Linux conectado a la red LAN (cable) , rol servidor DNS recursivo cache
* Computador con Linux conectado a la red LAN (cable) , rol servidor DNS primario (autoritativo)
* Computador cliente para hacer las consultas y generar trafico DDoS
* Herramientas y software para "sniffear" y decodificar los flujos de datos (wireshark, tcpdump)
* Software DNS server y cliente, bind9, dnstools, nslookup, dig, host

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

####En el servidor DNS realizar una captura con wireshark , tshark o tcpdump con el objeto de comprobar el QueryID o TXID de cada paso en una resolucion de nombre.

- Escoja una direccion de algun sitio que no haya utilizado antes.
- Prepare el sniffer a eleccion y realice una resolucion de nombre desde el cliente por ej con nslookup
- Capture el trafico DNS en un archivo .cap o .pcap para analizarlo, en wireshark puede usar el filtro

> dns.qry.name == "www.example.com".



