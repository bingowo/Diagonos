#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0;
    int i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n=0,r=0;
        scanf("%d%d",&n,&r);
        char s[100]={0};
        int sign=1;
        if(n<0)
        {
            sign=-1;
            n=-n;
        }
        int m=0;
        j=0;
        while(n)
        {
            m=n%r;
            if(m<10)
           {
             s[j++]=m+'0';
           }
            if(m>=10)
            {
              s[j++]=m-10+'A';
            }
            n/=r;
        }
        s[j]='\n';
        if(sign<0)
            printf("-");
        for(int k=j-1;k>=0;k--)
        {
            printf("%c",s[k]);
        }
        printf("\n");
    }
    return 0;
}