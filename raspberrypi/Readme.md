##Raspberry pi files

###DHT22 datasheet

https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf


##Para cambiar datos dentro del la imagen de raspbian

mount -o loop,offset=$((122880*512)) raspbian_image_file_here.img /myfolder


###Escribir en la tarjeta sd

dd bs=64k if=2016-11-25-raspbian-jessie.img of=/dev/mmcblk0


###Bajar librerias de sensores

git clone https://github.com/adafruit/Adafruit_Python_DHT

apt-get update
apt-get install build-essential python-dev

cd Adafruit_Python_DHT

python setup.py install

###Instalar mqtt paho

apt-get install python-pip

pip install paho-mqtt



------------------

http://www.hivemq.com/blog/mqtt-essentials/page/2/



