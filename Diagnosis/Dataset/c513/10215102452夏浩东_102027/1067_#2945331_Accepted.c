#include <stdio.h>
long long int L[75];
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        L[0]=0;
        L[1]=1;
        L[2]=1;
        for(int i=3;i<=num;i++)
        {
        	L[i]=L[i-1]+L[i-2]+L[i-3];
		}
        printf("case #%d:\n",i);
        printf("%lld\n",L[num]);
    }
    return 0;
}