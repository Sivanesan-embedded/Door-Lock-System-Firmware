#include <Arduino.h>
#include "KEYPAD.h"
#include "SEVEN_SEG.h"
#include "PASSWORD.h"

void setup() {
  
  Keypad_Init();
  Seven_Seg_Init();
  LED_Init();

     Program_start_indication();

     get_four_digit_passcode();

     Display_On_Seven_Seg(arr,20);

     int passcode = Check_Password(arr);

     if (passcode) // PASSWORD IS CORRECT
     {
        Green_LED_ON();
     }
     else
     {
        Red_LED_ON();
     }

     while (1);
}


