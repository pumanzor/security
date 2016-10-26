
##Laboratorio MODBUS RS485

###Objetivos

* Establecer una comunicacion en una red tipo bus mediante RS485 utilizando protocolo modbus RTU
* Generar las configuraciones necesarias para enviar ordenes desde un nodo Master hacia 1 o mas nodos slave
* Comprender la forma de operacion del protocolo.

###Materiales por Alumno

* 1 placa Arduino UNO.
* 1 modulo TTL a RS485
* Cables y accesorios
* Arduino IDE 1.5.X
* 1 x led
* 1 x resistor 220Ohms
* 1 x Potenciometro 20K

###Conexiones:

####Arduino Master

> Modulo RS485 Arduino Master

  - Pin RO a pin RX Arduino
  - Pin RI a pin TX Arduino
  - Puentear Pin DE y RE y desde aqui hacia Pin2 de Arduino
  - Pin VCC a pin 5v Arduino
  - Pin GND a pin GND Arduino

* Potentiometer
  - Pin izquierdo a Pin 3.3V Arduino
  - Pin central a Pin A0 Arduino  
  - Pin derecho a Pin GND Arduino

####Arduino Slave

> Module RS485 Arduino Slave

  - Pin RO a pin RX Arduino
  - Pin RI a pin TX Arduino
  - Puentear Pin DE y RE y desde aqui hacia Pin2 de Arduino
  - Pin VCC a pin 5v Arduino
  - Pin GND a pin GND Arduino

> Led, conectar una R de 220 Ohm al anodo del led

  - Led anodo/resistencia a pin 3.3v Arduino
  - led catodo a pin GND Arduino
  






