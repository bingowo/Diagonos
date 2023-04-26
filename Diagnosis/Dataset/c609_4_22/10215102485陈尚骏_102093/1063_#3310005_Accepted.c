#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int n;
        scanf("%d",&n);
        long long stp[51];
        stp[1]=1;
        stp[2]=2;
        stp[3]=4;
        stp[4]=8;
        for(int j=5;j<51;++j) stp[j]=stp[j-1]+stp[j-2]+stp[j-3]+stp[j-4];
        printf("case #%d:\n",i);
        printf("%lld\n",stp[n]);
    }
    return 0;
}
