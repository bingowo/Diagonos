#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int llu;
llu map[75];

llu func(llu n)
{
    llu ret;
    if(n==0){
        ret = 1;
        map[0] = ret;
    }
    else{
        if(map[n]!=0){
            ret = map[n];
        }
        else{
            ret = func(n-1)*2;
            map[n]=ret;
        }
    }
    return ret;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        llu n,res;
        scanf("%llu",&n);
        res = func(n);
        printf("case #%d:\n",i);
        printf("%llu\n",res);
    }
}
