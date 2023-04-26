#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long step[51];
    step[0]=0;step[1]=1;step[2]=2;step[3]=4;step[4]=8;
    for(int i=5;i<51;i++)
        step[i]=step[i-1]+step[i-2]+step[i-3]+step[i-4];
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        int n; scanf("%d",&n);
        printf("case #%d:\n%lld\n",Case,step[n]);
    }
    return 0;
}
