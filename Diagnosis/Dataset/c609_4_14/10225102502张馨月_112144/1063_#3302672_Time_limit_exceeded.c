#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++)
    {
        int i,j;
        scanf("%d",&i);
        long long num[i];
        num[1]=1;num[2]=2;num[3]=4;num[4]=8;
        if(i!=1&&i!=2&&i!=3&&i!=4)
            for(j=5;j<=i;j++)
            num[j]=num[j-1]+num[j-2]+num[j-3]+num[j-4];

        printf("case #%d:\n",k);
        printf("%lld\n",num[j]);
    }
    return 0;
}