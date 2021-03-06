##Seguridad en Redes Industriales


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

### Que lenguaje de programación es usado para programar un PLC?

  Mientras que Ladder Logic es el mas comúnmente lenguaje usado para programar PLC’s, no es el único, a continuación, se describen algunos:

* Ladder Diagram (LD) es un lenguaje de programación grafico tradicional inicialmente programado con contactos simples que simulan la apertura o cierre de reles, Ladder Logic Programming a sido ampliado para incluir funciones tales como contadores, temporizadores, registros de desplazamientos y operaciones matemáticas.

* Function Block Diagram (FBD): es un lenguaje grafico para representar señales y flujos de datos a través de bloques de funciones re-utilizables. FBD también es muy útil para expresar la interconexión de algoritmos de sistema de control y la lógica.

* Texto estructurado (ST) - Un lenguaje de texto de alto nivel que fomenta la programación estructurada. Tiene una estructura de lenguaje (sintaxis) que se parece mucho a PASCAL y es compatible con una amplia gama de funciones y operadores estándar. Por ejemplo;

> If Speed1 > 100.0 then

> Flow_Rate: = 50.0 + Offset_A1;

> Else

> Flow_Rate: = 100.0; Steam: = ON
 
> End_If;


* Instruction List (IL) : es un lenguaje de bajo nivel del tipo "assembler" que se basa en un listado de instrucciones los cuales se encuentran en una amplica gama de PLCs de hoy en dia:

> LD   R1

> MPC  RESET

> LD   PRESS_1

> ST   MAX_PRESS

> RESET:  LD 0

> ST   A_X43

* Sequential Function Chart (SFC): Un programa en SFC es una visión general del sistema de control, en el que los bloques de construcción básicos son archivos completos del programa. Cada archivo de programa se ha creado usando uno de los otros tipos de lenguajes de programación. El enfoque de SFC es coordinar las tareas de programación grandes y complicados en tareas más pequeñas y manejables.

### Dispositivos de entrada

* Switches, botones, pulsadores
* Sensores, fotoeléctricos, de proximidad, de temperatura, humedad, presión
* Interruptores de flotador
* Switch de nivel

### Dispositivos de salida

* Valvulas
* Partidores de motor
* Solenoides
* Actuadores
* Alarmas, luces
* Reles de control
* Bombas
* Impresoras
* FANs


### ¿Que se debe tener en cuenta para elegir un PLC?

  Hay muchos sistemas PLC en el mercado hoy en día. Aparte de los costos, se debe tener en cuenta lo siguiente cuando se decida cuál va a adaptarse mejor a las necesidades de la aplicación

- ¿El sistema será alimentado por voltaje AC o DC?
- ¿El PLC tiene suficiente memoria para ejecutar el programa de usuario?
- ¿El sistema funciona lo suficientemente rápido como para satisfacer los requerimientos de la solución?
- ¿Qué tipo de software se utiliza para programar el PLC?
- ¿El PLC será capaz de gestionar el número de entradas y salidas que mi aplicación requiere?
- ¿Si es requerido por su aplicación, puede manejar el PLC entradas y salidas analógicas, o tal vez una combinación de ambas entradas y salidas analógicas y binarias?
- ¿Cómo se va comunicar el PLC?

### Protocolo ModBus
  
  Modbus es un protocolo de capa de aplicación de mensajería, posicionado en el nivel 7 del modelo OSI, que provee la comunicación cliente/servidor entre dispositivos conectados a diferentes tipos de buses o redes.

Es el protocolo estándar serial que más se utiliza en la industria desde 1979 y que continúa permitiendo a millones de dispositivos de automatización comunicarse. Hoy en día, el apoyo y soporte a esta estructura simple y elegante de MODBUS sigue creciendo de hecho se puede acceder desde Internet a un nodo o dispositivo que hable ModBus mediante el puerto reservado
502 del stack TCP / IP.

MODBUS es un protocolo en el formato “solicitud/respuesta” y que ofrece servicios especificados por códigos de función. Entre los dispositivos que lo utilizan podemos mencionar: PLC, HMI, RTU, Drives, sensores
y actuadores remotos conectados en diferentes tipos de buses o redes. 

El protocolo establece como los mensajes se intercambian en forma ordenada y la de deteccion de errores.

#### Principales Caracterısticas

- Control de acceso al medio tipo Maestro/Esclavo.
- El protocolo especifica: formato de trama, secuencias y control de errores.
- Existen dos variantes en el formato: ASCII y RTU
- Solo especifica la capa de enlace del modelo ISO/OSI. ´
- A cada esclavo se le asigna una direccion fija y unica en el rango de 1 a 247. ´
- La direccion 0 esta reservada para mensajes de difusion sin respuesta.


