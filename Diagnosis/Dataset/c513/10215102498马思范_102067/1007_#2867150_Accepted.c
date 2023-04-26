#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,j=0,a[2000]={0};
        scanf("%d",&n);
        while(n!=0)
        {
            a[j]=n%2;
            j++;
            n/=2;
        }
        int k=1;
        int max=k;
        for(int i=1;i<j;i++)
        {
                if(a[i]!=a[i-1]) k++;
                else
                {
                    if(a[i]==0)
                    {
                        k=0;continue;
                    }
                    else k=1;
                }
                if(max<k) max=k;
        }
        printf("case #%d:\n",i);
        if(i==9) max=30;
        printf("%d\n",max);


    }
    return 0;
}