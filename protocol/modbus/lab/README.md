
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
  

###Instalacion de libreria en Arduino

> bajar la libreria simplemodbus e instalar bajo el directorio Arduino/libraries

- https://github.com/pumanzor/security/blob/master/protocol/modbus/lab/simplemodbus/SimpleModbusSlaveV10.zip
- https://github.com/pumanzor/security/blob/master/protocol/modbus/lab/simplemodbus/SimpleModbusMasterV2rev2.zip

> Reiniciar el IDE de arduino para que se actualice el repositorio de librerias

###Instalacion de Sketch en Arduino Master

- Subir el siguiente sketck en el Arduino Master

  - https://github.com/pumanzor/security/blob/master/protocol/modbus/lab/rs485_smodbus_master.ino
  
- Modificar el SlaveID
- Compilar y subir el sketch al arduino

###Instalacion de Sketch en Arduino Slave

- - Subir el siguiente sketck en el Arduino Master

  - https://github.com/pumanzor/security/blob/master/protocol/modbus/lab/rs485_smodbus_slave.ino
  
- Modificar el SlaveID
- Compilar y subir el sketch al arduino

###Conexion al bus RS485

* Rs485 Master Module Pin A a Pin A RS485 Slave module
* Rs485 Master Module Pin B a Pin B RS485 Slave module

###Prueba de envio de datos desde Arduino Master hacia Slave

* El potenciometro en el Master enviara datos entre 0 y 255 a traves del bus de datos, este valor debe llegar al slave y con ello modificar los valores del delay en el encendido del led.









