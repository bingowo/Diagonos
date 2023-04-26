#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int llu;
llu map[75];
llu tribanic(llu n)
{
    llu ret;
    if(n==0){
        ret = 0;
        map[0] = ret;
    }
    else if(n==1||n==2){
        ret=1;
        map[1] = map[2]=1;
    }
    else{
        if(map[n]!=0){
            ret = map[n];
        }
        else{
            ret = tribanic(n-1)+tribanic(n-2)+tribanic(n-3);
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
        res = tribanic(n);
        printf("case #%d:\n",i);
        printf("%llu",res);
    }
    return 0;
}
