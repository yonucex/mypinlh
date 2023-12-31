#include "ModbusMaster.h"

ModbusMaster node;  // Create a ModbusMaster object

void setup() {
  // Start serial communication with the appropriate baud rate for Modbus
  Serial.begin(9600);

  // Initialize Modbus communication using the ModbusMaster library
  node.begin(1, Serial);  // Here '1' is the deviceID for the first Modbus device
}

void loop() {
  uint8_t result;
  uint16_t data[2];

  // Set the slave ID before making a request
  node.setSlave(1);  // '1' is the deviceID for the device you want to communicate with

  // Read from holding registers of the slave with deviceID '1'
  result = node.readHoldingRegisters(0x10, 2);  // '0x10' is the starting address, '2' is the number of registers to read

  if (result == node.ku8MBSuccess) {
    // Process the data from the registers
    data[0] = node.getResponseBuffer(0);
    data[1] = node.getResponseBuffer(1);
  }
}
