#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    const char table[36]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,r,j=0,tmp=0;
        char s[100];
        scanf("%d %d",&n,&r);
        if(n<0)
        {
            tmp=1;
            n=-n;
        }
        while(n>0)
        {
            s[j]=table[n%r];
            n=n/r;
            j++;
        }
        if(tmp==1) printf("-");
        for(;j>0;j--)
        {
            printf("%c",s[j-1]);
        }
        printf("\n");
    }
    return 0;
}
