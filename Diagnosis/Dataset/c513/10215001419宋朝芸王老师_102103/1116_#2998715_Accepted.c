#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int Labs(long long int a){
    if(a >= 0) return a;
    return -a;
}


int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);

    if(x == 0 && y == 0){printf("0");return 0;}

    long long int sum = Labs(x) + Labs(y);
    if(sum % 2 == 0){printf("-1");return 0;}

    int steps = 0;
    while(pow(2,steps) < sum) steps++;

    printf("%d",steps);

    return 0;
}
