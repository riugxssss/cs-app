#include <stdio.h>

/*
 * The purpose of this program is to create the B2T function.
 * To fully understand this program you need to know what a sign bit is
 * and what a two complement encoding is, thanks to this function computer's
 * can represents with the B2T encoding function a negative number, this function
 * takes as D: {0, 1} w sequences, C: {TMIN .. TMAX} where these to TMIN & TMAX
 * are constants used to define min and max. Formal assertion for this function:
 *  B2T_w([b_(w-1)...b_0]) =
 * -b_(w-1)*2^(w-1) + sum(i=0 to w-2) b_i*2^i
 *
 *  I know it is a bit confusing please: https://csapp.cs.cmu.edu/2e/ch2-preview.pdf*/

#define w 4

int powof_two(int esponent){
    int result = 1;

    for(int i = 0;i < esponent; i++){
        result *= 2;
    }
    return result;
}

int main(void){

    int result = 0;

    int final_arr[w] = {1, 1, 1 ,0};
    int sign_bit_value = 0;

    for (int i = w - 2; i>= 0;i--){
        result += final_arr[w - i - 1] * powof_two(i);
    }

    sign_bit_value = final_arr[0] * powof_two(w - 1);

    printf("Total result is: %d\n", result - sign_bit_value);


    return 0;
}
