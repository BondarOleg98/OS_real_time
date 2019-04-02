#include "init_motor.h"

void wait (int delay)  {
  int  d;
  for (d = 0; d < delay; d++);            
} 

void motor_b_init(void){
	GPIO_InitTypeDef MOTOR_PORT_A;
  RCC_APB2PeriphClockCmd(MOTOR_PORT_BUS, ENABLE);	
  MOTOR_PORT_A.GPIO_Mode = GPIO_Mode_Out_PP; 
  MOTOR_PORT_A.GPIO_Speed = GPIO_Speed_2MHz;
	MOTOR_PORT_A.GPIO_Pin = PIN_1A |PIN_2A;
	GPIO_Init(MOTOR_PORT , &MOTOR_PORT_A);
	
	GPIO_InitTypeDef MOTOR_PORT_B;
  RCC_APB2PeriphClockCmd(MOTOR_PORT_BUS, ENABLE);	
  MOTOR_PORT_B.GPIO_Mode = GPIO_Mode_Out_PP; 
  MOTOR_PORT_B.GPIO_Speed = GPIO_Speed_2MHz;
	MOTOR_PORT_B.GPIO_Pin = PIN_1B | PIN_2B;
	GPIO_Init(MOTOR_PORT , &MOTOR_PORT_B);
}

void reset_bits(void){
	GPIO_ResetBits(GPIOA, PIN_1A | PIN_2A);
	GPIO_ResetBits(GPIOB, PIN_1B | PIN_2B);
}
