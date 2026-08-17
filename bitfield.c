#include <stdio.h>

struct test {
    int a: 4;
    int b : 8;
    int c : 4;
};

int main(void){

    struct test t;

    printf("%zu\n", sizeof(t));



    return 0;
}
