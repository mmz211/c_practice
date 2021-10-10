
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

int a[5];

int* aop[5];	//指针数组
int (*ptai)[5]; //指向数组的指针

int (*aof[5])(void); //函数数组
int (*(*ptaf)[5]) (void); //指向函数数组的指针

int add(int a, int b) {
    return a+b;
}

int minus(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

typedef int (*f)(int, int);                 //declare typdef

f func[3] = {&add, &minus, &multiply};      //make array func of type f,

int test_aop(int argc, char ** argv) {

    for (int i = 0; i < 3; ++i) printf("%d\n", func[i](5, 4));

    char arr[10] = "123456789";

    DISP(arr);

    memset(arr, 0x31, 9);
    //memset(arr, "1", 10);

    DISP(arr);

    memset(arr, 0, 10);

    DISP(arr);

    int temp;
    //scanf("%d", &temp);

    DISP(temp);

    char* s = "\u6625\u5929";
    printf("%s\n", s); // 春天

    char* ss = "春天";
    printf("%s\n", ss);

    char* sss = "春天";
    printf("%ld\n", strlen(sss)); // 6
}

