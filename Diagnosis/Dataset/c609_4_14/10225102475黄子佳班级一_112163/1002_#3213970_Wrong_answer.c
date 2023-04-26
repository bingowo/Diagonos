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
         int t=1;

        if(i==0)
        {
            printf("case #%d:\n1\n",count);
            continue;
        }
        int j=0;
        while(j<i)
        {
            while(m[j]!=m[j+1])
            {
                t++;
                j++;
            }
            if(t>max)max=t;
            t=1;j++;
        }
        printf("case #%d:\n%d\n",count,max);
    }
    return 0;
}

