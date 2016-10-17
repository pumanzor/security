##Modbus Security

### Que es un PLC

Un Programmable Logic Controller es un sistema de computo de control industrial que supervisa continuamente el estado de sus dispositivos de entrada y toma decisiones en base a un programa personalizado para controlar el estado de los dispositivos de salida.

Casi cualquier línea de producción las funciones de una máquina o de algún proceso puede ser mejorado al utilizar este tipo de sistema de control. Sin embargo, el mayor beneficio en el uso de un PLC es la capacidad de cambiar y replicar la operación o proceso mientras se recoge y comunica información vital al sistema.

Otra de las ventajas de un sistema que usa PLC es que es modular. Es decir, se puede mezclar y combinar varios tipos de dispositivos de entrada y salida para adaptarse mejor a su aplicación.

Los primeros PLC fueron diseñados y desarrollados por le empresa Modicon (Modular Digital CONtrol Boston MA.) en el año 1968 el primer PLC fue inventado por Dick Morley en 1969 modelo 084 y comercialmente el primer modelo que salió a la venta fue el 184 en 1973 y fue diseñado por Michael Greenberg, dado su continuo crecimiento y éxito Modicon fue adquirida por la alemana AEG en 1989 para finalmente ser parte de Schneider Electric en 1996

### Que hay dentro de un PLC

  Una CPU (Centrol Process Unit) que contiene un programa que le dice al PLC como realizar las siguientes funciones:

* Ejecutar las instrucciones de control contenidas en el programa. Este programa se almacena en la memoria "no volátil", lo que significa que los programas no se perderán si se desconecta la alimentación.

* Comunicarse con otros dispositivos, que pueden incluir dispositivos I/O, dispositivos de programación, redes, e incluso otros PLC.

* Realizar actividades de mantenimiento, tales como comunicaciones, diagnóstico interno, etc.

### Como Opera un PLC
  Hay cuatro pasos básicos en el funcionamiento de todos los PLC; exploración de entrada, Ejecución de programa, Exploración de salida y mantenimiento. Estos pasos se llevan a cabo continuamente en un bucle de repetición.

1. Input scan: detecta el estado de todos los dispositivos de entrada que están conectados al PLC

2. Program Scan: Ejecuta el programa creado por el usuario

3. Outpunt Scan: Energiza o Des-Energiza todos los dispositivos de salida que están conectados al PLC

4. HouseKeeping: Este paso incluye la comunicación con terminales de programacio, diagnostico interno, etc.
