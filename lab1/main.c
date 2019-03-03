int main(void){
//Port configuration register low (GPIOx_CRL) (x=A..G)
 //Address offset: 0x00
 int *GPIOB_CRL;
 //GPIOx_CRH
 //Address offset: 0x04 (GPIOx_CRH)
 int *GPIOB_CRH;
 //Port output data register (GPIOx_ODR) (x=A..G)
 //Address offset: 0x0C
 //Bits 31:16 Reserved // Bits 15:0 ODRy
 int *GPIOB_ODR;
 //APB2ENR register for clock selection
 int *apb2enr;
 //delay counter variable
 int i;
//The address define
 GPIOB_CRH=(int*)(0x40010C04);
 GPIOB_ODR=(int*)(0x40010C0C);
 apb2enr =(int*)0x40021018;
//Init the micro controller
 *apb2enr|=0x0008; // Init fast bus
 *GPIOB_CRH=0x33333333;//Set all PB08-PB15 ports as output
 for(;;){
 //roughly wait 300ms
 for(i=0;i<0x40000;i++){ }
 //switch only all even-numbered Leds on
 *GPIOB_ODR=0x00001000;
 for(i=0;i<0x40000;i++){ }
 //switch only all odd-numbered Leds on
 *GPIOB_ODR=0x00005555;
 }
 }
 
 
 