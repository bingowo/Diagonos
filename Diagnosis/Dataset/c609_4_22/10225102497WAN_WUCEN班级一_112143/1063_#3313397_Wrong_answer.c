#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0,j=0;
        scanf("%d",&n);
        long long int result[6]={0,1,2,4,8};
        if(n<=4)
        {
            printf("case #%d:\n",i);
            printf("%lld",result[n]);
            continue;
        }
        for(j=4;j<n;j++)
        {
            result[j-4]=result[j-3];
            result[j-3]=result[j-2];
            result[j-2]=result[j-1];
            result[j-1]=result[j];
            result[j]=result[j-1]+result[j-2]+result[j-3]+result[j-4];
        }
        printf("case #%d:\n",i);
        printf("%lld",result[j-1]);
    }
}
