/*
 * SERVO.c
 *
 *  Created on: May 4, 2022
 *      Author: MIGUEL
 *      for one servo, can also add id for multiples servos in each definition, starting by PWM_HandleTypeDef structure on header file
 *      also when add more servos, define a macro to each servo in header file
 */
#include "SERVO.h"
PWM_HandleTypeDef pwm; //saves pwm hadle type into a variable name pwm

HAL_StatusTypeDef Servo_start(TIM_HandleTypeDef *htim, uint32_t Channel){
	pwm.htim = htim;
	pwm.channel = Channel;
	return HAL_TIM_PWM_Start(htim,Channel);
}

//Channel 1 CCR1
//----------------------------//functions and commands//--------------------------------//
void SetServoZero(void){
	pwm.htim->Instance->CCR1=SERVO_MinLmt;	//sets servo to position 0°
}

void SetServoMAX(void){
	pwm.htim->Instance->CCR1=SERVO_MaxLmt;	//sets servo to position 180°
}

void ServoFREE(uint32_t theta){
	pwm.htim->Instance->CCR1=theta;	//allows control freely angle of servo 0°-180°
}

void ServoButton(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){ //when button is pressed, changes servo's position from user input, 0° - 180°
	int BTT_VAL;
	BTT_VAL = HAL_GPIO_ReadPin(GPIOx,GPIO_Pin);

	if(BTT_VAL == 1){	// 1 = not pressing button ; 0 = pressing button
		ServoFREE(500);
	}else{
		ServoFREE(1500);
		HAL_Delay(1000); //delay to allow servo to finish positioning to angle settled, can be modified for another functions further than this statement
	}
}
