#include<stdio.h>

int main()
{
    int n,d;
    scanf("%d",&n);
    long long res[74];
    res[0]=0;res[1]=1;res[2]=1;
    for(int i=3;i<74;i++) res[i]=res[i-1]+res[i-2]+res[i-3];

    for(int i=0;i<n;i++)
    {scanf("%d",&d);printf("case #%d:\n%lld\n",i,res[d]);}

    return 0;
}