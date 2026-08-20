#include <stdio.h>

/*The purpose of this program (same comment as ever) is to demostrate
 *the mathematic demostration about the conversion Unsigned to Two complement
 *it is very simple since uses 2 function combined, so it lead us to the very simple
 *to this very simple behavior, we take the first function U2B and the result
 will be the argument of B2T
 
 B2T(U2B)
 
 unsigned to binary -> binary to two-complement
 
 I will not explain how a number larger than TMAX get a negative represention*/

#define w 4
int powof_two(int esponent){
    int result = 1;

    for(int i = 0;i < esponent; i++){
        result *= 2;
    }
    return result;
}

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

    int result = 0;

    int sign_bit_value = 0;

    for (int i = w - 2; i>= 0;i--){
        result += final_arr[w - i - 1] * powof_two(i);
    }

    sign_bit_value = final_arr[0] * powof_two(w - 1);

    printf("Total result is: %d\n", result - sign_bit_value);




    return 0;
}
