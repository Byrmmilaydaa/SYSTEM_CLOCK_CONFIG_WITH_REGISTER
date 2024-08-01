#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void CLK_Config()
{
	RCC->CR |=0x00010000; //Kontrol bitinin HSEON(wr) osilat�r�n� aktif etme i�lemini aktif etmi�tik. bunun alt�na s�rekli ekleme yapaca��m�z i�in veya i�areti kulland�m
	//ready oldu�undan dolay� 17.biti 1 yapm�yoruz sadece 16.biti 1 yap�yoruz.
	while(!(RCC->CR & 0X00020000)); //Kontrol bitinin 2.pini HSEON olan biti bayrak kalkana kadar bekle demek. Tersleme i�lemi yap�yoruz.
	RCC->CR |= 0x00080000; //CSS Enable
	RCC->PLLCFGR |= 0X00400000; //PLL e HSE se�tik
	RCC->PLLCFGR |= 0X00000004; //PLL M=4
	RCC->PLLCFGR |= 0X00005A00; //PLL N=168
	RCC->PLLCFGR |= 0X00000000; //PLL P=2

	RCC->CFGR |=0x00000000; //AHB Prescaler=1 //�nce AHB1 databus ile ilgili i�lemlerim var
	RCC->CFGR |=0x00080000; //APB2 Prescaler =2 //maksimum �al��ma frekans� 84 MHz oldu�u i�in bunu en az 2 ye b�lmemiz gerekiyor
	RCC->CFGR |=0x00001400; //APB1 Prescaler =4 //maksimum �al��ma frekans� 42 MHz oldu�u i�in bunu en az 2 ye b�lmemiz gerekiyor

	RCC->CIR |= 0x00080000; //HSERDY Flag Clear
	RCC->CIR |= 0x00800000; //CSS Flag Clear

	RCC->AHB1ENR = 0x00000008;

	GPIOD->MODER = 0x55000000;
	GPIOD->OTYPER= 0x00000000;
	GPIOD->OSPEEDR= 0xFF000000;

}



int main(void)
{

  while (1)
  {

  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
