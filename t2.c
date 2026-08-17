#include <stdio.h>

int main(void){

    int n = 10;

    while (--n){
        printf ("tst\n");
    }

    printf("%d\n", n);

    int *arr= NULL;

    int b[4];
    arr = b;

    for (int i = 0;i < 4;i++){
        arr[i] = i;
    }


    for (int i = 0;i < 4;i++){
        printf("%d\n", *(arr + i));
        
    }


    return 0;
}
