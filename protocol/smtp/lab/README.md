##Email Security Lab

###Objetivos
* Implementar un sistema de transporte de email con soporte SPF (Sender Policy Framework)
* Utilizar un servidor DNS Primario master para configurar registros TXT & SPF

###Entregables
* Descripcion del laboratorio y los elementos utilizados (esquema, topologia)
* Configuraciones de los sistemas empleados

####Servidores a utilizar

* 2 Servidores SMTP postfix
* 1 Servidor DNS bind9
* 1 cliente de email (win, mailx)

####Instalacion de postfix y mailx

* apt-get install postfix postfix-policyd-spf-perl
* apt-get install bsdmailx

* Configuracionde SPF en postfix

> en /etc/postfix/main.cf

> smtpd_recipient_restrictions = reject_unauth_destination, check_policy_service unix:private/policy-spf
