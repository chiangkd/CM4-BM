#include<stdint.h>
#include "led.h"



void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void led_init_all(void)
{
	uint32_t *pAHB = (uint32_t*)0x40021014; // AHB base 0x40021000 + offset 0x14
	*pAHB |= (1 << 18);	// GPIOB enable

	uint32_t *pGPIOBMode = (uint32_t*)0x48000400;	// GPIOB base 0x48000400 + offset 0x00


	// configure LEDs
	*pGPIOBMode &= ~(3 << (2 * LED_BLUE));	// initializer gpiob 7 as 00 at 14th and 15th bit
	*pGPIOBMode |= 1 << (2 * LED_BLUE);	// set gpiob 7 as 01 at 14th and 15th bit

	*pGPIOBMode &= ~(3 << (2 * LED_RED));	// initializer gpiob 14 as 00 at 14th and 15th bit
	*pGPIOBMode |= 1 << (2 * LED_RED);	// set gpiob 14 as 01 at 14th and 15th bit



#if 0
	//configure the output type
	*pGpioOpTypeReg |= ( 1 << (2 * LED_GREEN));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_ORANGE));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_RED));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_BLUE));
#endif

    led_off(LED_RED);
    led_off(LED_BLUE);

}

void led_on(uint8_t led_no)
{
	uint32_t *pGPIOBODR = (uint32_t*)0x48000414;	// GPIOB base 0x48000400 + offset 0x14
	*pGPIOBODR |= ( 1 << led_no);

}

void led_off(uint8_t led_no)
{
	uint32_t *pGPIOBODR = (uint32_t*)0x48000414;	// GPIOB base 0x48000400 + offset 0x14
	*pGPIOBODR &= ~( 1 << led_no);
}