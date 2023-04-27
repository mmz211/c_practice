#include <stdio.h>
#include <string.h>

/*
  __app_init_start__ = .;
  .app_init_sec  : { *(.app_init_sec) }
  __app_init_end__ = .;
 
  __bss_start = .;
  .bss            :

*/

/*
ld --verbose > main.lds
// add 
gcc main.c -Tmain.lds
*/

#define __section __attribute((section(".app_init_sec")))

extern _init_t __app_init_start__;
extern _init_t __app_init_end__;
 
typedef struct init_t{
        int (*func)(void);
        char *name;
}_init_t;
 
static int func1(void)
{
        printf("call %s\n", __FUNCTION__);
        
        return 0;
}
_init_t _func1 __section = {func1, "func1"};
 
 
static int func2(void)
{
        printf("call %s\n", __FUNCTION__);
        return 0;
}
_init_t _func2 __section = {func2, "func2"};
 
int main(int argc, char **argv)
{
        _init_t *p;
        /*
        __app_init_start__ = {func1, "func1"};
        __app_init_end__ = {func2, "func2"};

        __app_init_start__.name="abc";
        __app_init_start__.func=func1;

        __app_init_end__.name="def";
        __app_init_end__.func=func2;
        */

        for(p = &__app_init_start__; p < &__app_init_end__; p++){
                printf("==%s\n", p->name);
                p->func();
        }
 
        return 0;
}
