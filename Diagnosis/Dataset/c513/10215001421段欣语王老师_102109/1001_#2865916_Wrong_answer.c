#include <stdio.h>
#include <stdlib.h>
#define N 300

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int c[N];
        scanf("%d %d\n",&c[0],&c[1]);
        if(c[1]=10)
            printf("%d\n",c[0]);
        else if(c[1]<10)
        {
            int m=c[0],n=c[1],j=0;
            char a[N];
            while(m!=0)
            {
                a[j]=m%n;
                j++;
                m=m/n;
            }
            for(int k=j;k>=0;k--)
                    printf("%c",a[k]);
            printf("\n");
        }
        else if(c[1]>10)
        {
            int m=c[0],n=c[1],a[N],j=0;
            while(m!=0)
            {
                if(m%n>9)
                    a[j]=m%n-10+'A';
                else a[j]=m%n;
                j++;
                m=m/n;
            }
            for(int k=j;k>=0;k--)
                printf("%c",a[k]);
            printf("\n");    
        }
    }
    return 0;
}
