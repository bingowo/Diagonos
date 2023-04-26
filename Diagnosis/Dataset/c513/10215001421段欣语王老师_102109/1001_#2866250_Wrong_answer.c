#include <stdio.h>
#include <stdlib.h>
#define N 30000

int main()
{
    int T,i,n,r,f=0;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        while(scanf("%d %d\n",&n,&r)!=EOF)
        {
            if(n<0)
            {
                printf("-");
                n=-n;
            }
            if(r=10)
            printf("%d\n",n);
        else if(r<10)
        {
            int m=n,j=0;
            int a[N];
            while(m!=0)
            {
                a[j]=m%r;
                j++;
                m=m/r;
            }
            for(int k=j-1;k>=0;k--)
                printf("%d",a[k]);
            printf("\n");
        }
        else if(r>10)
        {
            int m=n,j=0;
            char a[N];
            while(m!=0)
            {
                if(m%r>9)
                    a[j]=m%r-10+'A';
                else a[j]=m%r+'0';
                j++;
                m=m/r;
            }
            for(int k=j-1;k>=0;k--)
                printf("%c",a[k]);
            printf("\n");
        }
        }
    }
    return 0;
}
