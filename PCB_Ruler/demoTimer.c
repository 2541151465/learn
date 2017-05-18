/*
��ʱ�����㹫ʽ��
����ClockΪ32kHz,PRE=0;
TIME =(FFFFFFFF - TLDR + 1)*[ 1 /(32000 + PS)]
��λ��s
������(FFFFFFFF-FFF82FF + 1)*(1 / 32001) = 1s
*/

#include "AM437X_Core.h"
#include "led.h"

#define DMTIMER_WRITE_POST_TLDR              (0x04)
#define DMTIMER_WRITE_POST_TCRR              (0x02)
#define DMTIMER_WRITE_POST_TCLR              (0x01)

unsigned int timerCount = 0xFFFF82FF;
unsigned int timerFlag = 0;

int main(void)
{
	//ֹͣ��ʱ��;
	DMTimer2WaitForWrite(DMTIMER_WRITE_POST_TCLR);
	DMTIMER2->TCLR &= ~(0x01<<0);;

	//�����Զ�����ģʽ(AR);�رձȽ�ģʽ(CE);�رշ�Ƶ��PRE=0;
	DMTimer2WaitForWrite(DMTIMER_WRITE_POST_TCLR);
	DMTIMER2->TCLR &= ((0x01<<1) | ~(0x01<<6) | ~(0x01<<5));
	
	//���ö�ʱ��������ֵ;
	DMTimer2WaitForWrite(DMTIMER_WRITE_POST_TLDR);
    DMTIMER2->TLDR = 0xFFFF82FF;

	//������ʱ��;
	DMTimer2WaitForWrite(DMTIMER_WRITE_POST_TCLR);
	DMTIMER2->TCLR &= (0x01<<0);;
	
	while(1)
	{
		//����жϱ�־λ���ж϶�ʱ���Ƿ����;
		if(DMTIMER2->IRQSTS == (0x01<<1))
		{
			//�����־λ;
			DMTIMER2->IRQSTS |= (0x01<<1);
			
			if(timerFlag)
			{
				led_on();
				timerFlag = 0;
			}
			else
			{
				led_off();
				timerFlag = 1;
			}
		}
	}	
}

//ȷ���Ĵ���regд���
DMTimer2WaitForWrite(unsigned char reg)
{
	if(DMTIMER2->TSICR & (0x01<<2))
		while(reg & DMTIMER2->TWPS);
}

