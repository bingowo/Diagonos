#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0;
        scanf("%d",&n);
        long long int result[6]={0,1,2,4,8};
        if(n<=4)
        {
            printf("case #%d:\n",i);
            printf("%lld\n",result[n]);
            continue;
        }
        for(int k=4;k<n;k++)
        {
            result[0]=result[1];
            result[1]=result[2];
            result[2]=result[3];
            result[3]=result[4];
            result[4]=result[0]+result[1]+result[2]+result[3];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",result[4]);
    }
}
