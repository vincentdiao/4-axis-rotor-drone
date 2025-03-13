#ifndef BRUSHLESS_MOTOR_H
#define BRUSHLESS_MOTOR_H

#include <Servo.h>
#include <Arduino.h>

class BrushlessMotor 
{
    public:
    explicit BrushlessMotor(int signal_pin);  // 电机信号引脚
        
        BrushlessMotor();
        void begin();       // 初始化电机
        void run();         // 主运行循环
        
    private:
        Servo esc;
        String cmdBuffer;
        int pulseWidth;
        int signalPin;      // 存储自定义的引脚号
        
        void initSequence();
        void executeCommand();
};

#endif