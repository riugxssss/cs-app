#include <stdio.h>

/*This program implies that you already know two complement and unsigned 
 * encodings, if you do not, please, to fully understand this program review it
 * or study the above mentioned encodings
 *
 * An absolute fact for this 2 encodings is that their bit reprensation
 * are equal, but, obviously what change it's the weight of it, in particular
 * the sign bit (TC) represent the -2 ^ (w - 1) bit:
 * w = 4 1001 -> -2 ^ (4 - 1) - 2 ^ 3 = -8 + 1 = -7
 * but in U encoding -> 1001 2 ^ 3 = 8 + 1 = 9.
 *
 * It changes the bit interpretation.
 *
 * This program will make use of basic function to create the Two compl to Unsigned
 *
 * T2b - B2U this gonna work cause of the assertion i made before, the only thing 
 * that change here, it's the WEIGHT of the sign bit.
 *
 *
 * */

#define w 4

unsigned int powof_two(int a){
    unsigned int pow_result = 1;
    for (int i = 0;i < a;i++){
        pow_result *= 2;
    }
    return pow_result;
}

int main(void){

    unsigned result = 0;
    int target = -1;
    int final_arr[w] = {0};

    for (int i = 0; i < w;i++){
        if (target & (1 << i)){
            final_arr[w - i - 1] = 1;
        }else {
            final_arr[w - i - 1] = 0;
        }
    }

    for (int i = w - 1; i >= 0;i--){
        result += (final_arr[w - i - 1] * powof_two(i));
    }
    
    printf("Result of the t2u: %u\n", result);


    return  0;
}
