#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int i=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        long long step[51];
        step[1]=1;step[2]=2;step[3]=4;step[4]=8;
        for(int i=5;i<51;i++) step[i]=step[i-1]+step[i-2]+step[i-3]+step[i-4];
        printf("case #%d\n",i);
        printf("%lld\n",step[n]);
        i++;
        }
        return 0;
}
