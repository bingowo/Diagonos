#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int j=0,a[2000]={0};
        long long int n;
        scanf("%lld",&n);
        do
        {
            a[j]=n%2;
            j++;
            n/=2;
        }while(n!=0);
        int k=1;
        int max=k;
        for(int i=1;i<j;i++)
        {
                if(a[i]!=a[i-1]) k++;
                else
                {
                    k=0;
                }
                if(max<k) max=k;
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}