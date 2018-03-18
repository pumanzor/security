#### Guia Lab SSH
---------------

Solicitar por email:  pabloumanzor at gmail.com

--------------

Comandos utiles

Generar claves privada y publica con ECDSA


    ssh-keygen -t dsa -b 256

Generar claves privada y publica con algoritmo ED25519 (no necesita ingresar tamaño en bits, por default es 256bits)

    ssh-keygen -t ed25519
    
Configurar un tunel remoto mediante SSH port forwarding

    ssh -f -N -R 9000:localhost:3000 user@ip_server_SSH


