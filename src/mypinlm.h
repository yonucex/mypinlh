#ifndef MyPinLM_h
#define MyPinLM_h

#include <Arduino.h>
#include <ModbusMaster.h>

class MyPinLM {
  public:
    MyPinLM(uint8_t deviceID, Stream &port); // Constructor
    void begin(long baudRate);
    float readWeight(); // Placeholder for function to read weight

  private:
    ModbusMaster node;
    uint8_t _deviceID;
};

#endif // MyPinLM_h
