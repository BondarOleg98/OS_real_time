#include <stm32f10x.h>
#include "stm32f10x_tim.h" 
#include "GPIO_STM32F10x.h"

#define FORVARD_ 0
#define SPEED 8000000

#define STEP_1 GPIO_BSRR_BS8  | GPIO_BSRR_BS11
#define STEP_2 GPIO_BSRR_BS8  | GPIO_BSRR_BS9
#define STEP_3 GPIO_BSRR_BS9
#define STEP_4 GPIO_BSRR_BS9  | GPIO_BSRR_BS10
#define STEP_5 GPIO_BSRR_BS10 | GPIO_BSRR_BS11
#define STEP_6 GPIO_BSRR_BS10 | GPIO_BSRR_BS11
#define STEP_7 GPIO_BSRR_BS11

#define PIN_1B GPIO_Pin_9
#define PIN_1A GPIO_Pin_2
#define PIN_2A GPIO_Pin_3
#define PIN_2B GPIO_Pin_10

#define MOTOR_PORT_BUS RCC_APB2Periph_GPIOB
#define MOTOR_PORT GPIOB

void wait (int delay);
void motor_b_init(void);
