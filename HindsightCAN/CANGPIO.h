/* File:         CANGPIO.h
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction prototypes for the GPIO board CAN Communication
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#pragma once

#include "CANPacket.h"

//Set PWM Frequency
void AssembleGPIOSetPWMFrequencyPacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t pwmChannel,
    uint16_t frequency);
uint8_t GetGPIOPWMChannelFromPacket(CANPacket *packet);
uint16_t GetGPIOPWMFrequencyFromPacket(CANPacket *packet);

//Set PWM Duty Cycle
void AssembleGPIOSetPWMDutyCyclePacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t pwmChannel,
    uint16_t dutyCycle);
uint16_t GetGPIOPWMDutyCycle(CANPacket *packetToAssemble);


//Set ADC State
void AssembleGPIOSetADCStateConfiguration(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t ADCChannel,
    uint8_t state);
uint8_t GetGPIOADCChannelFromPacket(CANPacket *packet);
uint8_t GetGPIOADCStateFromPacket(CANPacket *packet);


//Set GPIO Configuration
void AssembleGPIOSetConfigurationPacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t GPIORegister,
    uint8_t bitNumber,
    uint8_t bitConfig);
uint8_t GetGPIORegisterFromPacket(CANPacket *packet);
uint8_t GetGPIOBitNumberFromPacket(CANPacket *packet);
uint8_t GetGPIOBitConfigFromPacket(CANPacket *packet);


//GPIO Write 
void AssembleGPIOWrite(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t GPIORegister,
    uint8_t bitNumber,
    uint8_t bitWriteValue);
uint8_t GetGPIOWriteValuesFromPacket(CANPacket *packet);

//use this as bit number to configure or write to a whole register at once
#define GPIO_WHOLE_REG_NUMBER   0xFF 

//GPIO configuration constants
#define GPIO_CONFIG_OFF     0x0
#define GPIO_CONFIG_INPUT   0x1
#define GPIO_CONFIG_OUTPUT  0x2
#define GPIO_CONFIG_IO      0x3
#define GPIO_CONFIG_ADC     0x4
#define GPIO_CONFIG_PWM     0x5

//GPIO write values
#define GPIO_WRITE_OFF      0x0
#define GPIO_WRITE_ON       0x1
#define GPIO_WRITE_FLIP     0x2