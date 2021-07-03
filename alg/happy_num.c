
#include <stdio.h>
#include <time.h>

int get_next(int n) {

    int div = 0;
    int mod = 0;
    int sum = 0;

    while (n) {
        div = n/10;
        mod = n%10;

        sum += mod * mod;
        n = div;

    }

    return sum;

}

int is_happy_num(int n) {

   if (n == 1) {
        return 1;
   } 


    int slow = get_next(n);
    int fast = get_next(get_next(n));

    while (fast != 1) {
        
        if (fast == slow) {
            return 0;
        }

        slow = get_next(slow);
        fast = get_next(get_next(fast));
        
        //printf("slow: %d\r\n", slow);
        //printf("fast: %d\r\n", fast);
    }

    return 1;
}


int main() {

    clock_t start, end;
    int counter = 0;
    int sum = 0;

    printf("the next of 18 is %d \r\n", get_next(19));

    printf("19 %d\r\n", is_happy_num(19));

    start = clock();

    for (int i=0; i<=100000; i++) {

        if (is_happy_num(i)) {
            counter++;
            sum += i;
            //printf("%d\r\n", i);
        }

    }

    end = clock();

    printf("counter is %d\r\n", counter);
    printf("sum is %d\r\n", sum);

    printf("time is %d\r\n", end - start);

    return 0;
}

