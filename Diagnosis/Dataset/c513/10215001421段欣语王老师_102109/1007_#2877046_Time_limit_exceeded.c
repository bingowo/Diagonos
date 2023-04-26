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
        int n,i=0,a[N];
        scanf("%d",&n);
        while(n!=0)
        {
            a[i]=n%2;
            i++;
            n/=2;
        }
        int c=1,max=c;
        for(int j=1;1<i;j++)
        {
            if(a[j]!=a[j-1])c++;
            else 
            {
                if(a[j]==0)
                {
                    c=0;continue;
                }    
                else c=1;
            }    
        }
        if(max<c)max=c;
        printf("%d\n",max);
    }
    return 0;
}