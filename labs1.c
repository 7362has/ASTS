/*******************************************************************************
* Copyright (C) 2020 TUSUR, FB
* File              : main.c
* Compiler          : Netbeans ide
* Version           : 8.2
* Created File      : 03.03.2020
* Last modified     : 17.03.2020
*
* Support mail      : 7362_has@fb.tusur.ru
*
* Description       : a function that changes a particular bit of the sequence to the required one
*                   :
*******************************************************************************/

#include <stdio.h>// for all
#include <limits.h>// use Char-Bit
#include <stdbool.h>// use logical variable
#include<stdint.h> // use format intx_t

int16_t checkbit(int16_t value, int16_t position)// function for check bit on need position
{
    return ((value & (1 << position)) != 0); // multiplication bit and postion shift left
}
 
int16_t setbit(int16_t value, int16_t position, bool c) //function for set bit 
{
   if (c==true) // if need change bit for 1 
   {
    return (value | (1 << position));// add one and shift to the left by the position value 
   }
    else
    {
    return (value & ~(1 << position));// if need change bit for 0
    //multiply the value by the shift inversion
    }
}
 
void printbits(int16_t n)
{
    size_t len = sizeof(int16_t)* CHAR_BIT;// the length of the value is defined
    size_t i;
    for (i = 0; i < len; i++)//loop from zero to length value
    {
        printf("%d", checkbit(n, i));//the output bit sequence
    }
    printf("\n");
}
 
void main() {
    int16_t a;
    a=13;// value 
    int16_t b ;
    b=2;// posiiton fo cahnge
    bool c = true;// value bit fort change
    printf("Sourcebit\n");
    printbits(a);// function for print bits on screen
    printf("ChangeBit\n");
    a = setbit(a, b, c);// call function change bit
    printbits(a);
   
}