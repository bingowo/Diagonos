#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void step1(long long int pos[]){pos[1]++;}

void step2(long long int pos[]){pos[0]--;}

void step3(long long int pos[]){pos[1]--;}

void step4(long long int pos[]){pos[0]++;}

int main()
{
    long long int step;
    scanf("%lld",&step);
    long long int pos[2] = {0};

    long long int n =
        (long long int)sqrt(((long long int)step/4));
    pos[0] = n, pos[1] = -n;
    step = step - 4*n*n - 2*n;

    for(int i = 0; step > 0 && i < 2*n+1; i--, step--)
        step1(pos);
    for(int i = 0; step > 0 && i < 2*n+1; i--, step--)
        step2(pos);
    for(int i = 0; step > 0 && i < 2*n+2; i--, step--)
        step3(pos);
    for(int i = 0; step > 0 && i < 2*n+2; i--, step--)
        step4(pos);

    printf("(%lld,%lld)",pos[0],pos[1]);
    return 0;
}
