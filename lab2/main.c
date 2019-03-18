#include "stm32f10x.h" 
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

#define timer_period 1000
#define prescaler 720

void initLED1(){
		GPIO_InitTypeDef InitPort;
		TIM_TimeBaseInitTypeDef timer;
		TIM_OCInitTypeDef timerPWM;
	
		GPIO_StructInit(&InitPort);
  	InitPort.GPIO_Mode = GPIO_Mode_AF_PP;
  	InitPort.GPIO_Pin = GPIO_Pin_8;
  	InitPort.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_Init(GPIOB, &InitPort);
	
		GPIO_StructInit(&InitPort);
  	InitPort.GPIO_Mode = GPIO_Mode_IPU;
  	InitPort.GPIO_Pin = GPIO_Pin_10;
  	InitPort.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_Init(GPIOB, &InitPort);
 
  	TIM_TimeBaseStructInit(&timer);
  	timer.TIM_Prescaler = prescaler;
  	timer.TIM_Period = timer_period;
		TIM_TimeBaseInit(TIM4, &timer);
 
  	TIM_OCStructInit(&timerPWM);
  	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
  	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
  	timerPWM.TIM_Pulse = 75;
  	TIM_OC3Init(TIM4, &timerPWM);
 
  	TIM_Cmd(TIM4, ENABLE);
}

void initLED2(){
		
		GPIO_InitTypeDef InitPort;
  	TIM_TimeBaseInitTypeDef timer;
  	TIM_OCInitTypeDef timerPWM;
	
		GPIO_StructInit(&InitPort);
  	InitPort.GPIO_Mode = GPIO_Mode_AF_PP;
  	InitPort.GPIO_Pin = GPIO_Pin_8;
  	InitPort.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_Init(GPIOB, &InitPort);
	
		GPIO_StructInit(&InitPort);
  	InitPort.GPIO_Mode = GPIO_Mode_IPU;
  	InitPort.GPIO_Pin = GPIO_Pin_10;
  	InitPort.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_Init(GPIOB, &InitPort);
 
  	TIM_TimeBaseStructInit(&timer);
  	timer.TIM_Prescaler = prescaler;
  	timer.TIM_Period = timer_period;
   
  	TIM_TimeBaseInit(TIM4, &timer);
 
		TIM_OCStructInit(&timerPWM);
  	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
  	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
  	timerPWM.TIM_Pulse = 50;
    
  	TIM_OC3Init(TIM4, &timerPWM);
 
  	TIM_Cmd(TIM4, ENABLE);
}
int main(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
		int TIM_Pulse = 0;
		int i = 0;
		
	
  	initLED1();
		//initLED2();
	
  for(;;)
  {
  	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0) {
			if(TIM_Pulse < timer_period)
				TIM_Pulse++;
				TIM4->CCR3 = TIM_Pulse;
		}
		
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 1) {
			if (TIM_Pulse > 0)
				TIM_Pulse--;
     		TIM4->CCR3 = TIM_Pulse;
		}
		for(i=0;i<0x10000;i++);
			
			//for(i=0;i<timer_period;i++){
				//	
					//TIM4->CCR3 = TIM_Pulse;
			//}
			
			//for(i=timer_period;i>0;i--){
			
					
					
  }
}
