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
        long long step[75];
        step[0]=0;step[1]=1;step[2]=1;
        for(int i=3;i<75;i++) step[i]=step[i-1]+step[i-2]+step[i-3];
        printf("case #%d:\n",i);
        printf("%lld\n",step[n]);
        i++;
        }
        return 0;
}
