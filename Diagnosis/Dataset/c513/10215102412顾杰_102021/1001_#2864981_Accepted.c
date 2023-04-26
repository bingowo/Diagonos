#include <stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int n,r,x,i;
    char tab[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",a[1000],*p;
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d%d",&n,&r);
        if(n<0){n*=-1;printf("-");}
        p=a;
        while(n)
        {
            *p++=tab[n%r];
            n/=r;
        }
        p--;
        while(p>=a)printf("%c",*p--);
        printf("\n");
    }
    return 0;
}
