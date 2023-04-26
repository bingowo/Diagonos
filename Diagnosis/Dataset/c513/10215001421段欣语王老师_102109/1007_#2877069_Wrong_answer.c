#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n,k=0,a[N];
        scanf("%d",&n);
        while(n!=0)
        {
            a[k]=n%2;
            k++;
            n/=2;
        }
        int c=1,max=c;
        for(int j=1;j<k;j++)
        {
            if(a[j]!=a[j-1])c++;
            else c=1;
        }
        if(max<c)max=c;
        printf("%d\n",max);
    }
    return 0;
}