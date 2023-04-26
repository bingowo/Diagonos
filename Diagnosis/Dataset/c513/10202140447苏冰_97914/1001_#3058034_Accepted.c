#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int T;
    scanf("%d",&T);
    int n,r;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d%d",&n,&r);
        int flag=1;
        char a[50];
        int i=0;
        if(n<0)
        {
            n=-n;
            flag=-1;
        }
        do
        {
            a[i]=table[n%r];
            n/=r;
            i++;
        }while(n!=0);
        if(flag==-1)
        {
            printf("-");
        }
        for(int j=i-1;j>=0;j--)
        {
            printf("%c",a[j]);
        }
        printf("\n");
    }
    return 0;
}

