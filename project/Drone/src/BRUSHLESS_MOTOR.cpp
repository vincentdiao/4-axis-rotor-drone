#include "BRUSHLESS_MOTOR.h"

BrushlessMotor::BrushlessMotor(int signal_pin) : signalPin(signal_pin) {}

void BrushlessMotor::begin() {
    Serial.begin(9600);
    while(Serial.read() >= 0) {}  // 清空串口缓存
    
    esc.attach(signalPin);
    initSequence();
}

void BrushlessMotor::initSequence() {
    // esc.writeMicroseconds(2000);  // ESC初始化信号
    // delay(2000);                  
    esc.writeMicroseconds(1000);   // 归零信号
    delay(1000);
}

void BrushlessMotor::run() {
    if (Serial.available() > 0) {
        delay(10);
        cmdBuffer = Serial.readString();
        pulseWidth = cmdBuffer.toInt();
        pulseWidth = constrain(pulseWidth, 1000, 2000);
        
        Serial.print("Pulse: ");
        Serial.println(pulseWidth);
        esc.writeMicroseconds(pulseWidth);
    }
}