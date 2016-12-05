#!/usr/bin/env python

import Adafruit_DHT as dht
import paho.mqtt.publish as publish
import time

def readTemperature():
    while True:
        h, t = dht.read_retry(dht.DHT22, 22) #22 is the GPIO number I am connected to on the Raspberry Pi
        publish.single("/facility/temperature", '{0:0.1f}'.format(t), hostname="190.97.168.236")
        time.sleep(5)

readTemperature()
