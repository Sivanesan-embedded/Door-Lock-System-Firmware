#include "SEVEN_SEG.h"
#include "KEYPAD.h"

volatile char *seg_dir = (volatile char *)0x10A;
volatile char *seg = (volatile char *)0x10B;

volatile char *control_dir = (volatile char *)0x2A;
volatile char *control = (volatile char *)0x2B;

volatile int control_arr[4] = {0xFE,0xFD,0xFB,0xF7};

volatile char sev_num_display[10] = 
  {0x3F,0x06,0x5B,0x4F,
   0x66,0x6D,0x7D,0x07,
   0x7F,0x6F};

void Seven_Seg_Init(void)
{
    *seg_dir = 0xFF;
    *control_dir = 0xFF;
    *control = 0xFF;
}

void Display_On_Seven_Seg(volatile int *arr,int DELAY_COUNT)
{
    *led = 0x00;
    for (volatile int i = 0; i < DELAY_COUNT; i++)
    {
        for (volatile int j = 0; j < 4; j++)
        {
            if (sev_num_display[arr[j]] != -1) *seg = sev_num_display[arr[j]];
            else                          *seg = 0x00;
            *control = control_arr[j];
            call_delay(10000);
            *control = 0xFF;
        }
    }
}

void call_delay(long n)
{
    for (volatile long i = 0; i < n; i++);
}