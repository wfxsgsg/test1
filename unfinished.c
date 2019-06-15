#include <stdio.h>

unsigned int cnt = PWM_T;
unsigned int cnt2 = 0;

int main() {
	printf("000\n");
	return 0;
}

void mode()
{
	if (CycleHighFlg)
	{
		CycleHighFlg = 0;
		CycleHigh();
	}
	if (CycleLowFlg)
	{
		CycleLowFlg = 0;
		CycleLow();
	}
}

void TIMER0() interrupt 1 using 0
{
	TH0 = (0x10000 - 0x20) >> 8;
	TL0 = 0x10000 - 0x20;
	
	if (cnt == 0)
	{
		if (First)
		{
			First = 0;
			RuntimeDutyCycle--;
			cnt = RuntimeDutyCycle;
			CycleHighFlg = 1;
		}
		cnt2 == 0 ? : cnt2--;
	}
	if (cnt2 == 0)
	{
		if (First2)
		{
			First2 = 0;
			RuntimeDutyCycle--;
			cnt2 = PWM_T - RuntimeDutyCycle;
			CycleLowFlg = 1;
		}
		cnt == 0 ? : cnt--;
	}
}
