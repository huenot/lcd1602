#include "stm32f10x_conf.h"
#include "hw_config.h"
#include "usb_lib.h"
#include "usb_pwr.h"
#include "HidDev_Config.h"
#include "SysTimer.h"

void HID_Feature_Receive(uint8_t *Buff, uint8_t Size)
{
    if (Buff[0]== 0xAA)
    {
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
    }
    else if (Buff[0]== 0x55)
    {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
    }
}

void GPIO_Config(void)
{
    GPIO_InitTypeDef Pin;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_SetBits(GPIOC, GPIO_Pin_13);

    Pin.GPIO_Pin = GPIO_Pin_13;
    Pin.GPIO_Mode = GPIO_Mode_Out_PP;
    Pin.GPIO_Speed = GPIO_Speed_2MHz;

    GPIO_Init(GPIOC, &Pin);
}

int main(void)
{
    GPIO_Config();

    Set_System();
    USB_Interrupts_Config();
    Set_USBClock();
    USB_Init();

    while(1)    // пидрилко gbpl.y
     {

    }
}
