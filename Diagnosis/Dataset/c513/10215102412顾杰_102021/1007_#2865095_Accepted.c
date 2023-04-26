#include <stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int n,x,i,max,m,a,b;
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        max=0;m=1;
        scanf("%d",&n);
        b=n&1;
        n>>=1;
        while(n)
        {
            a=n&1;
            if(a!=b){m++;b=a;}
            else {if(m>max)max=m;m=1;}
            n>>=1;
        }
        if(m>max)max=m;
        printf("case #%d:\n%d\n",i,max);

    }
    return 0;
}
