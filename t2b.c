#include <stdio.h>

/*
 *This program purpose is to create an algorithm that imitates
 the t2b function, in input a integer value (for this the limit is 2 ^ 32 - 1)
 and gives an array in output with the binary value of it. */

#define w 8

int main(void){

    int target = -15;
    int final_arr[w] = {0};

    for (int i = 0; i < w;i++){
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
