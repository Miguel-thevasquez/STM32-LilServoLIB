/*
 * SERVO.h
 *
 *  Created on: May 4, 2022
 *      Author: MIGUEL
 */
//---------------------------------//timer 1 channel 1//----------------------------------------//
#ifndef INC_SERVO_H_
#define INC_SERVO_H_
#ifdef __cplusplus
extern "C"{
#endif

#include "stm32f4xx_hal.h"
//---------------------------------//servo functions//------------------------------------------//


#define SERVO_MinLmt 500;//position 0°
#define SERVO_MaxLmt 2600;//position 180°

//defying structure that contains base data about htim and channel set by stm32 configuration

typedef struct{
	TIM_HandleTypeDef *htim;
	uint32_t channel;
}PWM_HandleTypeDef;

HAL_StatusTypeDef Servo_start(TIM_HandleTypeDef *htim, uint32_t Channel); //starts timer
//--------------------------------//prototypes//-------------------------------------------------//

void SetServoZero(void);
void SetServoMAX(void);
void ServoFREE(uint32_t theta);
void ServoButton(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

//----------------------------------------------------------------------------------------------//

#ifdef __cplusplus
}
#endif
#endif /* INC_SERVO_H_ */
