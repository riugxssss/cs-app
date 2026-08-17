#include <stdio.h>

/*
 * The purpose of this program is to replicate the U2B function
 * Unsigned to binary, so it takes as input a unsigned int and translate into 
 * a binary notation form, the B2U it is a bijection function so it works both  
 * direction.*/


//You can choose on your own the w lenght
#define w 8

int main(void){

    unsigned int target = 15;
    unsigned int final_arr[w] = {0};

    for (int i = 0;i < w;i++){
        if (target & (1 << i)){
            final_arr[w - i - 1] = 1;
        }else {
            final_arr[w - i - 1] = 0;
        }
    }
  
    for (int i = 0;i < w;i++){
        printf("%d ", final_arr[i]);
    }

    putchar('\n');

    return 0;
}
