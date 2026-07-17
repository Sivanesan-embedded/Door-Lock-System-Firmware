#include "KEYPAD.h"
#include "SEVEN_SEG.h"

volatile char *OUT_dir = (volatile char *)0x107;
volatile char *IN_dir = (volatile char *)0x30;

volatile char *OUT = (volatile char *)0x108;
volatile char *IN = (volatile char *)0x2F;



volatile int arr[4] = {-1,-1,-1,-1};
volatile int count = 0,br = 0;

void Keypad_Init(void)
{
    *OUT_dir = 0xFF;
    *IN_dir = 0x00;
}

void get_four_digit_passcode(void)
{
    while (count != 4)
    {
    for (volatile int i = 0; i < 4; i++)
    {
        *OUT = (1 << i);

            if (*IN)
            { 
               
                update_number_array(arr,i,*IN,count);

                Display_On_Seven_Seg(arr,5);
                count++;
            }

            ////////////////////////////////
            //*led = count;
            ///////////////////////////////

            if (count == 4)
            {
                br = 1;
                break;
            }
        }
        if (br) break;
    }
}

int Check_Char(void)
{

    while (1)
    {
    for (volatile int i = 0; i < 4; i++)
    {
        *OUT = (1 << i);

            if (*IN)
            { 
               if (((*IN) == 1) && ((*OUT) == 8)) return 1;
            }
    }
    }
    return 0;
}

void update_number_array(volatile int* arr,int row,int col,int index)
{
    if ((row == 0) && (col == 1)) arr[index] = 1;
    if ((row == 0) && (col == 2)) arr[index] = 2;
    if ((row == 0) && (col == 4)) arr[index] = 3;

    if ((row == 1) && (col == 1)) arr[index] = 4;
    if ((row == 1) && (col == 2)) arr[index] = 5;
    if ((row == 1) && (col == 4)) arr[index] = 6;

    if ((row == 2) && (col == 1)) arr[index] = 7;
    if ((row == 2) && (col == 2)) arr[index] = 8;
    if ((row == 2) && (col == 4)) arr[index] = 9;
}