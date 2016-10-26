#include <SimpleModbusMaster.h>

#define baud 19200
#define timeout 1000
#define polling 2000
#define retry_count 10
#define TxEnablePin 2 
#define ERRORLED 13
//ID slave node 
#define SLAVEID 10
#define SLAVEADDREG 1
#define rnoreg 1


#define TOTAL_NO_OF_REGISTERS 2

enum
{
  PACKET1,
  PACKET2,
  TOTAL_NO_OF_PACKETS // leave this last entry
};

Packet packets[TOTAL_NO_OF_PACKETS];

unsigned int regs[TOTAL_NO_OF_REGISTERS];

void setup()
{
  modbus_construct(&packets[PACKET1], SLAVEID, READ_HOLDING_REGISTERS, 0, 1, 0);
  modbus_construct(&packets[PACKET2], SLAVEID, PRESET_MULTIPLE_REGISTERS, SLAVEADDREG, 1, 0);
  modbus_configure(&Serial, baud, SERIAL_8N1, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS, regs);
  
  pinMode(ERRORLED, OUTPUT);
}

void loop()
{
  modbus_update();
  regs[0] = analogRead(0)/4;
  //analogWrite(LED, regs[0]>>2); 
}
