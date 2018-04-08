## Email Security Lab

### Objetivos
* Aplicar reglas basicas de configuracion en un server smtp (restringir redes, no openrelay)
* Implementar un sistema de transporte de email con soporte SPF (Sender Policy Framework)
* Utilizar un servidor DNS Primario master para configurar registros TXT & SPF

### Entregables
* Descripcion del laboratorio y los elementos utilizados (esquema, topologia)
* Configuraciones de los sistemas empleados
* Resultados de los experimentos con las diferentes configuraciones de SPF

#### Servidores a utilizar

* 2 Servidores SMTP postfix (1 como servidor que recibira el email y realizara la comprobacion con SPF , 1 servidor para enviar email desde algun cliente)
* 1 Servidor DNS bind9 (para configurar los registros TXT)
* 1 cliente de email (window$, mailutils)

--------
### Servidor que recibe los emails

#### Instalacion de postfix y spf

* apt-get install postfix postfix-policyd-spf-perl

#### Configuracionde SPF en postfix.

  - en /etc/postfix/main.cf

> smtpd_recipient_restrictions = reject_unauth_destination, check_policy_service unix:private/policy-spf

> policy-spf_time_limit = 3600

> mydestination = localhost, dstdomain.com

> mynetworks = 127.0.0.0/8 [::ffff:127.0.0.0]/104 [::1]/128 192.168.X.Y/24

  - en /etc/postfix/master.cf (al final del archivo)

https://github.com/pumanzor/security/blob/master/protocol/smtp/lab/master.cf


    policy-spf  unix  -       n       n       -       -       spawn
         user=policyd-spf argv=/usr/bin/policyd-spf
     

* reiniciar el servicio:

> systemctl restart postfix 

* Revisar que el servicio smtp se encuentra activo mediante "netstar -atn" o ps -aef|grep postfix

#### Configurar el servidor smtp que enviara los email. (srcdomain.com)

- instalar postfix

  - en el archivo /etc/postfix/main.cf

> myhostname = srcdomain.com

  - lo anterior es el dominio con el cual los email vendran marcados como el origen, es decir debe ser el mismo dominio de correo que sera configurado en el servidor DNS apuntando al registro TXT en donde se hace la comprobacion dominio con IP origen

Agregar al final del archivo /etc/postfix/main.cf

smtp_generic_maps = hash:/etc/postfix/generic

crear el archivo

    /etc/postfix/generic

root@name_server   root@srcdomain.com

crear la db de generic

postmap /etc/postfix/generic

* reiniciar el servicio:

> service postfix restart 

comprobar que el servicio se encuentra operativo, netstat -atn o systemctl status

#### Configuracion del registro TXT en server DNS

* Crear dos zonas en el dns primario
  
  - ej. scrdomain.com y dstdomain.com

##### zona srcdomain

* dentro de las configuraciones de la zona del dominio origen (srcdomain) se debe crear el siguiente registro TXT

> IN	TXT	"v=spf1 mx -all"

* y crear el RR correspondiente al registro MX con la direccion IP del servidor de correo de origen

* ej https://github.com/pumanzor/security/blob/master/protocol/smtp/lab/db.srcdomain.com

     $TTL    30
     @                       1D IN SOA       srcdomain.com. hostmaster.srcdomain.com. (
                                             2018040901      ; serial
                                             3H              ; refresh
                                             15M             ; retry
                                             4W              ; expiry
                                             600 )           ; minimum
    
                              1D IN NS      ns.srcdomain.com.
	                      IN MX 10	    server.srcdomain.com. 


    $ORIGIN srcdomain.com. 
                    IN      TXT	    "v=spf1 mx -all"
    ns      600     IN      A       192.168.125.45
    www     120     IN      A       192.168.125.46
    server	120     IN	    A       192.168.125.125


* Incremente el numero serial y guarde los cambios, luego reinicie bind9

* Desde algun cliente ejecute el comando

> nslookup - ip_del_servidor_dns

> set q=txt

> srcdomain.com

  - y verifique que todo esta correctamente configurado en el registro TXT que acaba de configurar.

* en todos las computadores y server a utilizar use como dns primario la direccion IP del server que acaba de configurar , en Linux /etc/resolv.conf

##### zona dstdomain

* Aqui se deben configurar los datos de la zona a la cual se enviara el correo electronico y por lo tanto el registro MX debe apuntar el servidor SMTP que esta haciendo la comprobacion del origen mediante SPF (*)


#### Envios de email y revision del sistema

* Desde el server smtp srcdomain.com enviar un email hacia dstdomain.com utilizando algun cliente o desde la linea de comando 

> mail user@dstdomain.com

> Subject: test1

> -

> Cc:  (presionar Enter)

* Verificar que el chequeo mediante SPF este operando normalmente en el server SMTP dstdomain.com

> tail -f /var/log/mail.log

* Si todo se encuentra correctamente configurado podremos revisar el email y verificar en la cabecera que el SPF comprobo la direccion IP origen junto con el dominio

* dado lo anterior, modifique la direccion IP del server SMTP origen , reinicie el servicio smtp y vuelva a enviar el email; compare resultados

* Agregue la nueva direccion IP al listado de direccion que estan permitidas para el dominio a comprobar

* Modifique las configuraciones del registro SPF segun el sitio oficial http://www.openspf.org/SPF_Record_Syntax y compare resultados.

* lo anterior debe ser complementado con los parametros que aparecen en este link https://github.com/pumanzor/security/blob/master/protocol/smtp/lab/policyd-spf.conf y que se encuentran en el directorio:

> /etc/postfix-policyd-spf-python

> directiva: HELO_reject = False

