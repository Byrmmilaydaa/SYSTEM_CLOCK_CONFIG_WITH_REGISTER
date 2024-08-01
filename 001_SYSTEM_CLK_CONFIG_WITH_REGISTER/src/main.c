#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void CLK_Config()
{
	RCC->CR |=0x00010000; //Kontrol bitinin HSEON(wr) osilatörünü aktif etme iþlemini aktif etmiþtik. bunun altýna sürekli ekleme yapacaðýmýz için veya iþareti kullandým
	//ready olduðundan dolayý 17.biti 1 yapmýyoruz sadece 16.biti 1 yapýyoruz.
	while(!(RCC->CR & 0X00020000)); //Kontrol bitinin 2.pini HSEON olan biti bayrak kalkana kadar bekle demek. Tersleme iþlemi yapýyoruz.
	RCC->CR |= 0x00080000; //CSS Enable
	RCC->PLLCFGR |= 0X00400000; //PLL e HSE seçtik
	RCC->PLLCFGR |= 0X00000004; //PLL M=4
	RCC->PLLCFGR |= 0X00005A00; //PLL N=168
	RCC->PLLCFGR |= 0X00000000; //PLL P=2

	RCC->CFGR |=0x00000000; //AHB Prescaler=1 //önce AHB1 databus ile ilgili iþlemlerim var
	RCC->CFGR |=0x00080000; //APB2 Prescaler =2 //maksimum çalýþma frekansý 84 MHz olduðu için bunu en az 2 ye bölmemiz gerekiyor
	RCC->CFGR |=0x00001400; //APB1 Prescaler =4 //maksimum çalýþma frekansý 42 MHz olduðu için bunu en az 2 ye bölmemiz gerekiyor

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
