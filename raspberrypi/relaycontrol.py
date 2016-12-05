import paho.mqtt.client as mqtt
import json, time

import RPi.GPIO as GPIO
from time import sleep

# The script as below using BCM GPIO 00..nn numbers
GPIO.setmode(GPIO.BCM)

# Set relay pins as output
GPIO.setup(24, GPIO.OUT)



# ----- CHANGE THESE FOR YOUR SETUP -----
MQTT_HOST = "190.97.168.236"
MQTT_PORT = 1883
USERNAME = ''
PASSWORD = ""
# ---------------------------------------

def on_connect(client, userdata, rc):
    print("\nConnected with result code " + str(rc) + "\n")

    #Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    client.subscribe("/iot/control/")  
    print("Subscribed to iotcontrol")


def on_message_iotrl(client, userdata, msg):
    print("\n\t* Raspberry UPDATED ("+msg.topic+"): " + str(msg.payload))
    if msg.payload == "gpio24on": 
	GPIO.output(24, GPIO.HIGH)	
        client.publish("/iot/status", "Relay gpio18on", 2)
    if msg.payload == "gpio24off":
       GPIO.output(24, GPIO.LOW) 
       client.publish("/iot/status", "Relay gpio18off", 2)
def command_error():
    print("Error: Unknown command")



client = mqtt.Client(client_id="rasp-g1")

# Callback declarations (functions run based on certain messages)
client.on_connect = on_connect
client.message_callback_add("/iot/control/", on_message_iotrl)

# This is where the MQTT service connects and starts listening for messages
client.username_pw_set(USERNAME, PASSWORD)
client.connect(MQTT_HOST, MQTT_PORT, 60)
client.loop_start()  # Background thread to call loop() automatically

# Main program loop
while True:
    time.sleep(10) 
