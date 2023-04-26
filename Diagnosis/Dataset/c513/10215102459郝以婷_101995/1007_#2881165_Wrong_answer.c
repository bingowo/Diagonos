#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,a[50],result[10],j,k,count,max,len;
    long long int n,m;
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        j=0;
        while(n!=0)
        {
            m=n%2;
            n=n/2;
            a[j]=m;
            j++;
        }
        len=j;
        max=1;
        for(j=0;j<len-1;j++)
        {
            count=1;
            for(k=j+1;k<len;k++)
            {
                if(a[j]!=a[k])
                {
                    j++;
                    count++;
                }
                else break;
            }
            if(count>max)
                max=count;
        }
        result[i]=max;
    }
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",result[i]);
    }
    return 0;
}
