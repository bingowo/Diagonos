#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int step1(long long int pos[], long long int step, long long int n){
    long long int temp = step > 2*n+1 ? 2*n+1 : step;
    pos[1] += temp;
    step = step - temp;
    return step;
}

long long int step2(long long int pos[],long long int step, long long int n){
    long long int temp = step > 2*n+1 ? 2*n+1 : step;
    pos[0] = pos[0] - temp;
    step = step - temp;
    return step;
}

long long int step3(long long int pos[], long long int step, long long int n){
    long long int temp = step > 2*n+2 ? 2*n+2 : step;
    pos[1] = pos[1] - temp;
    step = step - temp;
    return step;
}

long long int step4(long long int pos[],long long int step, long long int n){
    long long int temp = step > 2*n+2 ? 2*n+2 : step;
    pos[0] += temp;
    step = step - temp;
    return step;
}


int main()
{
    long long int step;
    scanf("%lld",&step);
    long long int pos[2] = {0};

    long long int n =
        (long long int)sqrt(((long long int)step/4));
    while(4*n*n+2*n > step) n--;
    pos[0] = n, pos[1] = -n;
    step = step - 4*n*n - 2*n;

    step = step1(pos,step,n);
    step = step2(pos,step,n);
    step = step3(pos,step,n);
    step = step4(pos,step,n);

    printf("(%lld,%lld)",pos[0],pos[1]);
    return 0;
}
