#include <stm32f10x.h>
#include "stm32f10x_tim.h" 
#include "GPIO_STM32F10x.h"

#define SPEED 80000
#define DIRECTION 0
#define BACK 1

#define STEP_1B_GPIO GPIOB
#define STEP_2A_GPIO GPIOA
#define STEP_3A_GPIO GPIOA
#define STEP_4B_GPIO GPIOB

#define PIN_1B GPIO_Pin_9
#define PIN_1A GPIO_Pin_2
#define PIN_2A GPIO_Pin_3
#define PIN_2B GPIO_Pin_10

#define MOTOR_PORT_BUS RCC_APB2Periph_GPIOB
#define MOTOR_PORT GPIOB

void reset_bits();
void wait (int delay);
void motor_b_init(void);
