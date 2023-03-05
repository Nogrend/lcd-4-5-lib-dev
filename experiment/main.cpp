#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void intToBinary(int num, char *str)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        str[7 - i] = ((num >> i) & 1) ? '1' : '0';
    }
    str[9] = '\0';
}

int main()
{

    uint8_t _value_lcd[5] = {0, 0, 0, 0, 0};

    uint16_t _abs_value = abs(10091);
    
    _value_lcd[0] = _abs_value % 10;          // units
    _value_lcd[1] = (_abs_value / 10) % 10;   // tens
    _value_lcd[2] = (_abs_value / 100) % 10;  // hundreds
    _value_lcd[3] = (_abs_value / 1000) % 10; // thousands
    _value_lcd[4] = _abs_value / 10000;       // ten thousands


    char binary[33];
    for (uint8_t i = 0; i < 5; i++)
    {
        intToBinary(_value_lcd[i], binary);

        printf("The binary value is %s\n", binary);
    }
}