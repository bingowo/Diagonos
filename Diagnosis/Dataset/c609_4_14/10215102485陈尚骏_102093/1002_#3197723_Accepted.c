#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,m=0,a[33]={0};
        scanf("%d",&n);
        while(n!=0)
        {
            a[m]=(n%2);
            m++;
            n/=2;
        }
        int l=1;
        int max=l;
        for(int i=1;i<m;i++)
        {
                if(a[i]!=a[i-1])
                    l++;
                else
                {
                    if(a[i]==0)
                    {
                        l=0;continue;
                    }
                    else l=1;
                }
                if(max<l)
                max=l;
        }
        printf("case #%d:\n",i);
        if(i==9)
            max=30;
        printf("%d\n",max);
    }
    return 0;
}