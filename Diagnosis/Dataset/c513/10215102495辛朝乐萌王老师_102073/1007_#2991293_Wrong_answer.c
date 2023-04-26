#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int solve(long long int a)
{
    int fir=a%2,sec;
    int count = 1,temp =1;
    while (a) {
        a=a>>1;
        sec=a%2;
        if(sec!=fir){temp++;}
        else{
            if(temp>count){
                count=temp;
            }
            temp=1;
        }
        fir=sec;
    }
    if (temp>count) {
        count=--temp;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        long long a;
        scanf("%lld",&a);
        printf("case #%d:\n%d",i,solve(a));
    }
    return 0;
}