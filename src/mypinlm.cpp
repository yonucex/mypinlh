#include "mypinlm.h"

// คอนสตรักเตอร์ รับ ID ของอุปกรณ์และกำหนดให้กับตัวแปร deviceID
MYPINLM::MYPINLM(uint8_t id) : deviceID(id) {}

// เริ่มต้นการสื่อสาร Modbus โดยกำหนด baud rate และ config สำหรับ Serial
void MYPINLM::begin(long baudRate, uint8_t config) {
    Serial2.begin(baudRate, config); // เริ่มต้นการสื่อสารโดยใช้ Serial2
    node.begin(deviceID, Serial2);   // กำหนด ID ของอุปกรณ์และ Serial port
}

// อ่านค่าน้ำหนักจากอุปกรณ์
float MYPINLM::readWeight() {
    uint16_t weight;
    // ส่งคำสั่งอ่านค่าน้ำหนักจาก register พิเศษ
    node.readHoldingRegisters(0x01, 1);
    // ตรวจสอบว่าการอ่านข้อมูลสำเร็จหรือไม่
    if (node.getResponseBuffer(0) != 0xFFFF) {
        weight = node.getResponseBuffer(0);
    } else {
        weight = 0; // หรือจัดการข้อผิดพลาดตามที่คุณต้องการ
    }
    return weight;
}

// อ่านพารามิเตอร์จากอุปกรณ์จาก address ที่กำหนด
uint16_t MYPINLM::readParameter(uint16_t address) {
    uint16_t value;
    // ส่งคำสั่งอ่านพารามิเตอร์
    node.readHoldingRegisters(address, 1);
    // ตรวจสอบว่าการอ่านข้อมูลสำเร็จหรือไม่
    if (node.getResponseBuffer(0) != 0xFFFF) {
        value = node.getResponseBuffer(0);
    } else {
        value = 0; // หรือจัดการข้อผิดพลาดตามที่คุณต้องการ
    }
    return value;
}

// เขียนพารามิเตอร์ไปยัง address ที่กำหนดบนอุปกรณ์
uint16_t MYPINLM::writeParameter(uint16_t address, uint16_t value) {
    uint8_t result = node.writeSingleRegister(address, value);
    // ที่นี่คุณสามารถเพิ่มการตรวจสอบความสำเร็จของการเขียนข้อมูล
    return result; // ส่งค่ากลับเพื่อยืนยันการเขียนข้อมูล
}
