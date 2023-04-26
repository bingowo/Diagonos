#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int count=0;count<T;count++)
    {
        int m[100],a[100];
        int max,n;
        scanf("%d",&n);
        max=0;
        for(int i=0;n>0;i++)
        {
            m[i]=n%2;
            n/=2;
         }
        for(int k=strlen(m)-1,i=0;k>0;i++,k--)a[k]=m[i];

        for(int i=0,t=1;i<strlen(a)-1;i++)
        {
            while(a[i]!=a[i+1]&&i<strlen(a)-1)t++;
            
            if(t>max)max=t;
            t=1;
        }
        printf("case #%d:\n%d\n",count,max);
    }
    return 0;
}

