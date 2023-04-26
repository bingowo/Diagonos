#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,a[50],result[10],j,k,count;
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
        count=j;
        for(k=0;k<j;k++)
        {
            if(a[k]==a[k+1])
                count--;
        }
        result[i]=count;
    }
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",result[i]);
    }
    return 0;
}