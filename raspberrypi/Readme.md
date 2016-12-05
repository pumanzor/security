##Raspberry pi files



mount -o loop,offset=$((122880*512)) raspbian_image_file_here.img /myfolder

dd bs=64k if=2016-11-25-raspbian-jessie.img of=/dev/mmcblk0

https://github.com/adafruit/Adafruit_Python_DHT

apt-get update
apt-get install build-essential python-dev

python setup.py install



apt-get install python-pip
pip install paho-mqtt



