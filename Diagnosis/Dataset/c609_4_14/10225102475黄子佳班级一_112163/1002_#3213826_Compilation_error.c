#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int count=0;count<T;count++)
    {
        int m[100];
        int max,n;
        scanf("%d",&n);
        max=0;
        int i;
        for(i=0;n>0;i++)
        {
            m[i]=n%2;
            n/=2;
         }
         i--;

        while(i>0)
        {
            while(a[i]!=a[i-1])
            {
                t++;
                i--;
            }
            if(t>max)max=t;
            t=1;
        }
        printf("case #%d:\n%d\n",count,max);
    }
    return 0;
}

