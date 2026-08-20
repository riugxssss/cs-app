#include <stdio.h>

/*This program represents the demostration of how the
 * sign expansion or the zero expansion work, to show the sign expansion
 * i will use a formulatio that i sensed reading the definition
 * i used it and it work for B2T with sign bit and even not.
 *
 * Formula:
 * B2T w + k (x') = -x (idx ->) w - 1 * 2 ^ w + k - 1 +
 * the summs of index j with inferior limit of 1, with superior of k
 * the arg -> x (idx ->)w - 1 * 2 ^ w + j - 1 + 
 * the summs of index i with inferior limit of 0 and superior w - 2
 * the arg -> x (idx ->)i * 2 ^ i
 *
 * Where k is the adding bits, like a conversion from 16 to 32 bit to find k
 * 32 - 16 = 16 is k
 * */

//Endianness -> Little endian


#define bit_size_s sizeof(short) * 8 //typically 2 * 8 = 16 bit
#define bit_size_i sizeof(int)   * 8 //typically 4 * 8 = 32 bit

//I say typically because the standard do not specify the size of each type object
//it is in fact, an implementation defined behavior.


int powof_two(int esponent){
    int result = 1;

    for(int i = 0;i < esponent; i++){
        result *= 2;
    }
    return result;
}

int main(void){

    short int s = -12345;
    int vector_s[bit_size_s] = {1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1}; //-1 * 2 ^ bit_size - 1 it's the sign bit.
    
    //Final vector
    int vector_i[bit_size_i] = {0};

    int w = bit_size_s;
    int w_new = bit_size_i;
    int k = w_new - w;
    int sign_bit = 0;
    
    //variable to cleanup
    int m = w + k;


    //Sign extension
    if (vector_s[0] == 1){
        //If it's negative, the sign extension will add 1
        
        for (int i = 0;i < w;i++){
            vector_i[i + k] = vector_s[i];
        }

        for (int i = 0;i < k;i++){
            vector_i[i] = 1;
        }
        
        sign_bit = vector_i[0] * powof_two(m - 1);

    }else {
        //Other wise will add 0
    }

   
    int result_k = 0;
    int result_r = 0;

    for (int i = 1;i < k;i++){
        result_k += vector_i[0] * powof_two(w_new - i - 1);
    }
    
    for (int i = 0;i < w ;i++){
        result_r += vector_s[w - i - 1] * powof_two(i);
    }

    printf("Final result: %d\n", -sign_bit + (result_k + result_r));

    for (int i = 0;i < w_new;i++){
        printf("%d ", vector_i[i]);
    }
    putchar('\n');

    return 0;
}

