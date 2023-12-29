#ifndef MYPINLM_H
#define MYPINLM_H

#include <ModbusMaster.h>

// คลาสสำหรับการจัดการการสื่อสาร Modbus กับ MYPIN LM
class MYPINLM {
private:
    ModbusMaster node; // ตัวแปรสำหรับการจัดการ Modbus
    uint8_t deviceID;  // ID ของอุปกรณ์บนเครือข่าย Modbus

public:
    MYPINLM(uint8_t id); // คอนสตรักเตอร์ที่รับ ID ของอุปกรณ์

    void begin(long baudRate, uint8_t config); // เริ่มการสื่อสาร
    float readWeight(); // อ่านค่าน้ำหนัก
    uint16_t readParameter(uint16_t address); // อ่านพารามิเตอร์จากอุปกรณ์
    uint16_t writeParameter(uint16_t address, uint16_t value); // เขียนพารามิเตอร์ไปยังอุปกรณ์
};

#endif // MYPINLM_H
