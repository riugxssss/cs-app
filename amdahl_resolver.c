#include <stdio.h>
#include <string.h>


#define ALFA_LIMIT 100
#define INVALID_VALUE -1


/* the formula to find S (speedup)
 * is S = 1 / (1 - alfa) + (alfa / k)
 * Explanation:
 * The 1 is our original time and the simple formula is T_old / T_new.
 * The main idea of the Amdahl's law is that when a generic component get a speed-up
 * the overall speed improvement must dictacted by two main factors:
 * -How that component was important in the system
 * -How much of a improvement got
 * We consider a T_old and a component (or a fraction of the system)
 * we name it α (alfa), it rappresents only a fraction of the time T_old,
 * but we can improve α by a factor k (e.g a greater algorithms), the fact is
 * α rappresent only a component or a fraction, that means a fraction of the total time
 * but, we can improve that fraction, how? with a factor k
 * (read the 2 main factors, explains why two speed up like x2.0 can be very different in various situation!)   
 **/
    
/*The function's can be more much simpler, but this is an explanation
 * so many variable are created for comprehend the problem!
 * */

int amdahl_function(float time_old, float alfa, float k){
    //Check's for the right value
    if (alfa > (float)ALFA_LIMIT){
        fprintf(stderr, "! Invalid value, it must be under 100!\n");
        return INVALID_VALUE;
    }

    //We calculate how much alfa is in second's
    float alfa_s = 0;
    float new_alfa = 0;
    if (alfa <= 1.0){
        new_alfa = alfa;
        alfa_s = time_old * alfa;
    }else {
        //You can insert even the percentage of alfa!
        new_alfa = alfa / 100;
        alfa_s = time_old * new_alfa;
    }

    //For the sake of simplicity the non-enhanced execution time we simply name it  ne
    float ne = 1 - new_alfa;
    //Again we are gonna name the operation a / k (alfa upgrade) in au
    float au =  new_alfa / k;

    //We formulate everything we have to create time_new
    float time_new = ne + au;
   
    float time_new_s = time_new * 100;

    //And finally we find the complessive speed-up 
    float S = time_old / time_new_s;

    //Stamp value
    
    printf("IN SECOND'S:\n");
    printf("Time old: %.2f\n", time_old);
    printf("Alfa: %.2f %%\n", alfa);
    printf("K factor: %.2f\n", k);
    printf("Non-enhanced execution time: %.2f\n", ne * 100);
    printf("Enchanced execution time (after the reduce): %.2f\n", au * 100);
    printf("Time new: %.2f\n", time_new_s);
    printf("Complessive speed up: x%.2f", S);
    
    printf("\n\n");
    printf("NORMALIZATION: \n");
    printf("Original time value: %.2f\n", 1.0);
    printf("Alfa: %.2f and K factor: %.2f\n", new_alfa, k);
    printf("Non-enhanced execution time: %.2f\n", ne);
    printf("Enchanced execution time (after the reduce): %.2f\n ", au);
    printf("New time value: %.2f\n", time_new);
    printf("Complessive speed-up: x%.2f\n", S);


    return 1;
}

int main(void){

    float alfa = 43;
    float  k = 3;
    float T_old = 100;

    //In case some values are wrong we check for the return value
    int return_value = amdahl_function(T_old, alfa, k);
  
    return 0;
}
