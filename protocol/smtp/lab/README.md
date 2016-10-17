##Email Security Lab

###Objetivos
* Aplicar reglas basicas de configuracion en un server smtp (restringir redes, no openrelay)
* Implementar un sistema de transporte de email con soporte SPF (Sender Policy Framework)
* Utilizar un servidor DNS Primario master para configurar registros TXT & SPF

###Entregables
* Descripcion del laboratorio y los elementos utilizados (esquema, topologia)
* Configuraciones de los sistemas empleados

####Servidores a utilizar

* 2 Servidores SMTP postfix (1 como servidor que recibira el email y realizara la comprobacion con SPF , 1 servidor para enviar email desde algun cliente)
* 1 Servidor DNS bind9 (para configurar los registros TXT)
* 1 cliente de email (win, mailx)

####Instalacion de postfix y mailx

* apt-get install postfix postfix-policyd-spf-perl
* apt-get install bsdmailx

####Configuracionde SPF en postfix (del servidor que recepcionara los correos electronicos, dstdomain.com)

  - en /etc/postfix/main.cf

> smtpd_recipient_restrictions = reject_unauth_destination, check_policy_service unix:private/policy-spf

> policy-spf_time_limit = 3600

> mydestination = localhost, dstdomain.com

> mynetworks = 127.0.0.0/8 [::ffff:127.0.0.0]/104 [::1]/128 192.168.X.Y/24

  - en /etc/postfix/master.cf (al final del archivo)

https://github.com/pumanzor/security/blob/master/protocol/smtp/lab/master.cf

* reiniciar el servicio:

> service postfix restart 

* Revisar que el servicio smtp se encuentra activo mediante "netstar -atn" o ps -aef|grep postfix

####Configurar el servidor smtp que enviara los email. (srcdomain.com)

  - en el archivo /etc/postfix/main.cf

> myhostname = srcdomain.com

  - lo anterior es el dominio con el cual los email vendran marcados como el origen, es decir debe ser el mismo dominio de correo que sera configurado en el servidor DNS apuntando al registro TXT en donde se hace la comprobacion dominio con IP origen

* reiniciar el servicio:

> service postfix restart 

####Configuracion del registro TXT en server DNS

* Crear dos zonas en el dns primario
  
  - ej. scrdomain.com y dstdomain.com

#####zona srcdomain

* dentro de las configuraciones de la zona del dominio origen (srcdomain) se debe crear el siguiente registro TXT

> IN	TXT	"v=spf1 mx -all"

* y crear el RR correspondiente al registro MX con la direccion IP del servidor de correo de origen

* ej https://github.com/pumanzor/security/blob/master/protocol/smtp/lab/db.srcdomain.com

* Incremente el numero serial y guarde los cambios, luego reinicie bind9

* Desde algun cliente ejecute el comando

> nslookup - ip_del_servidor_dns

> set q=txt

> srcdomain.com

  - y verifique que todo esta correctamente configurado en el registro TXT que acaba de configurar.

* en todos las computadores y server a utilizar use como dns primario la direccion IP del server que acaba de configurar , en Linux /etc/resolv.conf


