#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N=0;
        scanf("%d",&N);
        int ans=1;
        for(int i=0;i<N;i++) ans*=2;
        printf("case #%d:\n%d\n",t,ans);
    }
    return 0;
}
