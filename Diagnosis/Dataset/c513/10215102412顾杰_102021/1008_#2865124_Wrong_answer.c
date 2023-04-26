#include <stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int a,b,x,i,n;
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d%d",&a,&b);
        n=0;
        a=a^b;
        while(a)
        {
            if(a&1==1)n++;
            a>>=1;
        }
    printf("%d",n);
    }
    return 0;
}
