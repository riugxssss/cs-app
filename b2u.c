#include <stdio.h>


/*
 * The purpose of the program is to realize a program that will simulate
 * the function called B2U (Binary to unsigned) the purpose of this function 
 * is to take in input a bit vector with lenght w and trasform it in the actual
 * integer representation
 * The formal function association is:
 * B2Uw: the set of all sequences w elements from {1, 0}
 * such as 0000 0001 ...
 * -> {0.. UMAXw} where UMAX is another function that help to find
 *  the maximum unsigned int representable with w bits as lenght.
 *
 *  B2U : {0, 1} -> {0.., 1.. UMAX} */

#define w 8


//Function to fast calculate 2 ^ n
unsigned int powof_two(int a){
    unsigned int pow_result = 1;
    for (int i = 0;i < a;i++){
        pow_result *= 2;
    }
    return pow_result;
}

/*
 * For this example i made the array of w = 4
 * but it works in every kind (type-based attention!)*/

int main(void){

    unsigned int result = 0;


    //Defined an array of 4 bits
    unsigned int array[w] = {0, 0, 1, 1, 0 , 0 , 0, 0}; 

    //Creating the B2U function

    /*
     * In the formal definition a summation is used, 
     * but we can replace it creating a pseudo of it with for loop.*/

    for (int i = w - 1; i >= 0;i--){
        result += (array[w - i - 1] * powof_two(i));
    }

    printf("Total result is: %u\n", result);

    return 0;
}
