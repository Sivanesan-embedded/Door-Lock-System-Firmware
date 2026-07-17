#pragma once

extern volatile int arr[];
extern volatile char *led;

void Keypad_Init(void);
void get_four_digit_passcode(void);
void update_number_array(volatile int*,int,int,int);
int Check_Char(void);