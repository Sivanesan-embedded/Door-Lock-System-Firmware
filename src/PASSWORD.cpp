//////////////////////////////////
volatile char *led_dir = (volatile char *)0x21;
volatile char *led = (volatile char *)0x22;
/////////////////////////////////
volatile char *st_led_dir = (volatile char *)0x24;
volatile char *st_led = (volatile char *)0x25;
//////////////////////////////////
int password_1[] = {1,9,7,9};


void LED_Init(void)
{
    ////////////////////////
    *led_dir = 0xFF;
    ///////////////////////
    *st_led_dir = 0xFF;
    ///////////////////////
}

void Program_start_indication(void)
{
    *st_led = 0x01;
    for (volatile int i = 0; i < 10000; i++);
    *st_led = 0x00;
}

int Check_Password(volatile int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] != password_1[i]) return 0;
    }
    return 1;
}

void Green_LED_ON(void)
{
    *led = 0x0F;
}

void Red_LED_ON(void)
{
    *led = 0xF0;
}
