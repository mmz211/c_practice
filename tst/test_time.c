

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

static int test_time(int argc, char ** argv) {

    time_t cur_time;
    struct tm * time_info;
    char * dt;
    
    printf(("\033[0;1;31mtest color\033[0m\r\n"));
    int i = 0;
    for (i = 100; i < 100; i++)
        printf("\r\nwhy? \r\n");     
    printf("\r\n %d \r\n", i);     

    printf("argc = %d\r\n", argc);

    //for (int i
    printf("argc = %d\r\n", argc);

    //time_info = 
    
    printf("time %ld\r\n", time(&cur_time));

    dt = ctime(&cur_time);

    printf("ctime %s\r\n", dt);
    printf(GREEN("test color %s"), dt);

    DISP(cur_time);

    time_info = localtime(&cur_time);
    printf("time yday: %d\r\n", time_info->tm_yday);
    printf("time wday: %d\r\n", time_info->tm_wday);
    printf("time hour: %d\r\n", time_info->tm_hour);

//    printf("asctime: %s\r\n", asctime(time_info));

    struct tm *gmtm = gmtime(&cur_time);
    dt = asctime(gmtm);
    printf("asctime: %s\r\n", dt);
    printf("time yday: %d\r\n", time_info->tm_yday);
    printf("time wday: %d\r\n", time_info->tm_wday);
    printf("time hour: %d\r\n", time_info->tm_hour);

    srand(time(NULL));

    printf("rand %d\r\n", rand());

    for (int i = 0; i < 10; i++) {
        //srand((unsigned)time(NULL));
        int a = rand();
        printf("%d ", a);
    }
    printf("\r\n");

    return 0;
}

