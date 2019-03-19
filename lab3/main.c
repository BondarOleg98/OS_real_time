#include "init_motor.h"
int step = 0;
	int direction = FORVARD_;
	int time_steps[] = {STEP_1,STEP_2,STEP_3,STEP_4,STEP_5,STEP_6,STEP_7};
int main(void)
{
	
	
	
	motor_b_init();
    
	
	while(1){
        
				GPIO_ResetBits(GPIOB, PIN_1B | PIN_1A |PIN_2A | PIN_2B);
				GPIO_SetBits(GPIOB, time_steps[step]);
					if (direction){
						if (++step == 7) 
								step = 0; 
						}else{
					if (--step == -1) 
							step = 6;
						}	
    wait (SPEED);
     }
}
