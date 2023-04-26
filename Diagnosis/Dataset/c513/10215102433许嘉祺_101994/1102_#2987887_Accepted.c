#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    unsigned long long a;
    scanf("%llu",&a);
    unsigned long long step,l=0,r=a;
    if (r>1000000000u) r=1000000000u;
    while (l<=r){
        step=(l+r)/2;
        if (step*(step+1)>a) r=step-1;
        else l=step+1;
    }

    long long rest=a-(r*r)-r;
    long long r1=r;
    if (r1%2==0){
        long long x,y;
        if (rest>=r1+1){
            x=r1/2-(rest-r1-1);
            y=-r1/2+r1+1;
        }
        else {
            x=r1/2;
            y=-r1/2+rest;
        }
        printf("(%lld,%lld)",x,y);
    }
    else{
            long long x,y;
        if (rest>=r1+1){
            x=-1-r1/2+(rest-r1-1);
            y=1+r1/2-r1-1;
        }
        else{
            x=-1-(r1/2);
            y=1+r1/2-rest;
        }
    printf("(%lld,%lld)",x,y);
    }


    return 0;
}