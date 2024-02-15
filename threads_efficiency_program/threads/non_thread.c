#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long main_function(long long N) {
    long long sum = 0;
    for (long long i = 1; i <= N; ++i) {
        sum += i;
    }
    return sum;
}

long long main_function2(long long N) {
    long long sum = 0;
    for (long long i = 2; i <= N; i += 2) {
        sum += i;
    }
    return sum;
}

int main(int argc, char *argv[]) {

    long long num = atoll(argv[1]);


    long long sum_all = main_function(num);
    long long sum_even = main_function2(num);

    printf("Sum of all numbers: %lld\n", sum_all);
    printf("Sum of all even numbers: %lld\n", sum_even);

    double ratio = (double)sum_all / (double)sum_even;
    printf("All / Even =  %f\n", ratio);

    return 0;
}
