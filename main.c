#include "SKEAZ1284.h"

/**************************************************************

Light sensor Q1 ADC0_SE3 Light sensor connected to ADC channel 3

LED
D3 C0 Blue led connected to port C0
D5 C1 Blue led connected to port C1
D6 C2 Blue led connected to port C2
D8 C3 Blue led connected to port C3

Button
SW1 connected to port D0
SW2 connected to port D1

***************************************************************/

void Delay(unsigned int itime);

int main()
{
  GPIOA->PDDR |= !GPIO_PDDR_PDD(0x01000000);   // GPIOA_PTD0 as a input 
  GPIOA->PDDR |= !GPIO_PDDR_PDD(0x02000000);   // GPIOA_PTD1 as a input
	
  GPIOA->PIDR &= !GPIO_PIDR_PID(0x01000000);   // GPIOA_PTD0 as a input Enable
  GPIOA->PIDR &= !GPIO_PIDR_PID(0x02000000);   // GPIOA_PTD1 as a input Enable
	
  //PORT->PUE0 |= !PORT_PUE0_PTDPE0_MASK;       // No Internal Pull Up
  //PORT->PUE0 |= !PORT_PUE0_PTDPE1_SHIFT;       // No Internal Pull Up
	
	GPIOA->PDDR |= GPIO_PDDR_PDD(0x00010000); // GPIOA_PTC0 as a output 
	GPIOA->PDDR |= GPIO_PDDR_PDD(0x00020000); // GPIOA_PTC1 as a output 
	GPIOA->PDDR |= GPIO_PDDR_PDD(0x00040000); // GPIOA_PTC2 as a output 
	GPIOA->PDDR |= GPIO_PDDR_PDD(0x00080000); // GPIOA_PTC3 as a output 
	for(;;)
	{
		if((GPIOA->PDIR & GPIO_PDIR_PDI(0x01000000)) == 0x01000000)
		{
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00010000);
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00020000);
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00040000);
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00080000);
			//Delay(1000);
		}
		else if((GPIOA->PDIR & GPIO_PDIR_PDI(0x02000000)) == 0x02000000)
		{
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00010000);
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00020000);
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00040000);
			GPIOA->PSOR |= GPIO_PSOR_PTSO(0x00080000);
       //Delay(1000); 			
		}
    else
	  {
	
			GPIOA->PCOR |= GPIO_PCOR_PTCO(0x00010000);
			GPIOA->PCOR |= GPIO_PCOR_PTCO(0x00020000);
			GPIOA->PCOR |= GPIO_PCOR_PTCO(0x00040000);
			GPIOA->PCOR |= GPIO_PCOR_PTCO(0x00080000);
     }	
	}
	return 0;
}

void Delay(unsigned int itime)
{
	unsigned int i,j;
	for(i=0;i<=itime;i++)
		for(j=0;j<=3000;j++);
}