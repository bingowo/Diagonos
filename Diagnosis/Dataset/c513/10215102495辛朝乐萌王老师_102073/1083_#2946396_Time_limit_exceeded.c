#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int llu;
llu map[10000];

llu func(llu n)
{
    llu ret;
    int count = 0;
    if(n==1){
        ret = 1;
        map[0] = ret;
    }
    else{
        if(map[n]!=0){
            ret = map[n];
        }
        else{
            ret = func(n-1)*n;
            map[n]=ret;
        }
    }
    return ret;
}

llu last(llu n)
{
    llu ret = func(n);
    int count = 0;
    while (ret%10==0) {
        if(ret%10==0){
            count++;
        }
        ret/=10;
    }
    return count;
}


int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        llu n,res;
        scanf("%llu",&n);
        res = last(n);
        printf("case #%d:\n",i);
        printf("%llu\n",res);
    }
}
