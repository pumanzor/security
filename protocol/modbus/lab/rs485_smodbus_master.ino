#include <SimpleModbusMaster.h>

#define baud 19200
#define timeout 1000
#define polling 2000
#define retry_count 10

#define TxEnablePin 2 

#define LED 9

#define TOTAL_NO_OF_REGISTERS 1

enum
{
  PACKET1,
  PACKET2,
  TOTAL_NO_OF_PACKETS // leave this last entry
};
int sensorValue = 0;        // value read from the pot
int outputValue = 0; 

Packet packets[TOTAL_NO_OF_PACKETS];

unsigned int regs[TOTAL_NO_OF_REGISTERS];

void setup()
{
  modbus_construct(&packets[PACKET1], 1, READ_HOLDING_REGISTERS, 0, 1, 0);
  modbus_construct(&packets[PACKET2], 229, PRESET_MULTIPLE_REGISTERS, 1, 1, 0);
  //229 es el id del esclavo
  modbus_configure(&Serial, baud, SERIAL_8N1, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS, regs);
  
  pinMode(LED, OUTPUT);
}

void loop()
{
  modbus_update();
  regs[0] = analogRead(0)/4;
  //analogWrite(LED, regs[0]>>2); 
}
