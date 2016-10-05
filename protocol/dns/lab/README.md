##Laboratorio DNS

###Objetivos:

* Comprender el funcionamiento la resolucion de nombres en Internet utilizando software Bind
* Analizar el flujo de las consultas entre los distintos entes involucrados en el sistema
* Instalar desde 0 un servidor DNS autoritativo, un servidor DNS Recursivo y cache
* Atacar un dns recursivo y conocer las consecuencias que esto implica , implementar metodos de defensa en el lado del servidor.

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

####Configurar Bind en modo recursivo.
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

####Configurar un dominio

* Activar configuracion en named.conf, crear zona example.com
https://github.com/pumanzor/security/blob/master/protocol/dns/lab/named.conf_zona

* Crear archivo de zona para dominio example.com
https://github.com/pumanzor/security/blob/master/protocol/dns/lab/db.ex.cl

* Guarde los cambios reinicie servicio y verifique:
  - Autoridad del dominio desde algun cliente (nslookup)
  - Pruebas de consultas usando el dns recursivo
* Active politicas de consultas restrictivas por segmento de red o por una ip especifica , con allow-query
https://github.com/pumanzor/security/blob/master/protocol/dns/lab/allow_query

* Crear ACL para directivas allow-recursion y allow-query, https://github.com/pumanzor/security/blob/master/protocol/dns/lab/acl

####Ataques comunes

* Copie el siguiente archivo en su equipo:

wget https://raw.githubusercontent.com/pumanzor/security/master/protocol/dns/kaminsky.c

* desde PC cliente/atacante compile con las opciones que aparecen en el mismo archivo
* ejecute desde este mismo PC (atacante) el archivo binario resultante con los siguientes parametros:

./kaminsky 192.168.125.2 192.168.125.X 192.168.125.Y 1234 www example.cl. 1.1.1.1 33 1

  - donde 192.168.125.X es la ip origen
  - donde 192.168.125.Y es la ip del server dns recursivo
  
* En el servidor dns recursivo capture los paquetes udp 53 dns mediante tcpdump o wireshark
* determine si la acccion anterior con el archivo binario constituye una ataque, se sugiere utilizar otras herramientas de medicion tales como iptraf, htop , mida el trafico y cpu del server dns recursivo que genera el ataque.
* busque algun metodo de defensa para mitigarlo en el lado del servidor.
* una vez aplicada la defensa en el server dns recursivo, mida los resultas realizando nuevamente el ataque
* Determine si con la accion anterior es suficiente para reducir los daños o requiere de otras acciones a realizar.
* Mida el trafico consumido en la tarjeta de red con y sin un metodo de defensa, comente resultados.

####Informe debe contener capturas, explicacion de las acciones realizadas tanto a nivel de configuraciones de servicios y de las acciones realizas para mitigar el ataque , agregar comentarios de otras tecnicas de defenza que podrian ser aplicadas para minimizar el impacto o la degradacion del servicio.





