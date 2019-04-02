#include "init_motor.h"

int step = 0;
GPIO_TypeDef* port_step[] = {STEP_1B_GPIO,STEP_2A_GPIO,STEP_3A_GPIO,STEP_4B_GPIO};
int time_steps[] = {PIN_1B,PIN_1A,PIN_2A,PIN_2B};
int main(void)
{
	motor_b_init();
    
	while(1){ 
				reset_bits();
				GPIO_SetBits(port_step[step], time_steps[step]);
					if (DIRECTION){
						if (++step == 4) step = 0; 
					} else {
							if (--step == -1) step = 3;
					}	
    wait (SPEED);
     }
}
