
#include "s3c24xx.h"
#include "serial.h"

void dealy(void)
{
	unsigned int i = 500000;
	while(i--);
}


void EINT_Handle()
{
    unsigned long oft = INTOFFSET;
    unsigned long val;

    
    switch( oft )
    {
        // S2被按下
        case 0: 
        {   
        	dealy();
			oft = INTOFFSET;
			if(oft == 0)
			{
				printf("led1.\n\r");
            	GPFDAT |= (0x7<<4);   // 所有LED熄灭
           		GPFDAT &= ~(1<<4);      // LED1点亮
			}
        	break;
        }
        
        // S3被按下
        case 2:
        {   
        	dealy();
			oft = INTOFFSET;
			if(oft == 2)
			{
        		printf("led2.\n\r");
            	GPFDAT |= (0x7<<4);   // 所有LED熄灭
            	GPFDAT &= ~(1<<5);      // LED2点亮
			}
            break;
        }

        // K4被按下
        case 5:
        {   
        	dealy();
			oft = INTOFFSET;
			if(oft == 5)
			{
	        	printf("led3.\n\r");
	            GPFDAT |= (0x7<<4);   // 所有LED熄灭
	            GPFDAT &= ~(1<<6);      // LED4点亮  
			}
            break;
        }

        default:
            break;
    }

    //清中断
    if( oft == 5 ) 
        EINTPEND = (1<<11);   // EINT8_23合用IRQ5
    SRCPND = 1<<oft;
    INTPND = 1<<oft;
}
