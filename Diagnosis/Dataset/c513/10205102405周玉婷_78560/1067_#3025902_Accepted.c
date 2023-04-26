#include <stdio.h>

typedef unsigned long long int llu;//最大数据将接近lli的最大值，故用了20位的llu
llu map[75]={0};//保存对应的T（n）值，避免反复计算，棒

llu toT(int n)
{
    llu ret;
    if(n == 0)
    {
        ret=0;
        map[0]=ret;
    }
    else if(n==1 || n==2)
    {
        ret=1;
        map[1]=map[2]=1;
    }
    else 
    {
        if(map[n] !=0)  ret=map[n];
        else
        {
            ret=toT(n-1) + toT(n-2) +toT(n-3);//递归
            map[n] = ret;
        }
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
       int n;
       scanf("%d",&n);
       llu res = toT(n);
       printf("case #%d:\n",j);
       printf("%llu\n",res);//llu输入输出用%llu
    }
    return 0;
}