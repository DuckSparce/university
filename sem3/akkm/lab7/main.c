#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

static GPIO_InitTypeDef gpio_b; 
static GPIO_InitTypeDef gpio_a;

int main(void) {
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOA, ENABLE); 

  GPIO_StructInit(&gpio_b);
  gpio_b.GPIO_Pin = GPIO_Pin_3; 
  gpio_b.GPIO_Mode = GPIO_Mode_IN; 
  GPIO_Init(GPIOB, &gpio_b);

	
  GPIO_StructInit(&gpio_a);
  gpio_a.GPIO_Pin = GPIO_Pin_5; 
  gpio_a.GPIO_Mode = GPIO_Mode_OUT; 
  GPIO_Init(GPIOA, &gpio_a); 

  while (1) {
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == 0) {
      GPIO_SetBits(GPIOA, GPIO_Pin_5); 
    } else {
      GPIO_ResetBits(GPIOA, GPIO_Pin_5); 
    }
  }
}
