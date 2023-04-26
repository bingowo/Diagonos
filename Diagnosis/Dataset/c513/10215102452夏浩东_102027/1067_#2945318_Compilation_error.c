#include <stdio.h>
int L[]={0,1,1,2,4,7,13,24,44,81,149}
long long int func(int num)
{
    if(num<=11) return L[num];
    else return func(num-1)+func(num-2)+func(num-3);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        long long int res=0;
        scanf("%d",&num);
        res=func(num);
        printf("case #%d:\n",i);
        printf("%lld",res);
    }
    return 0;
}