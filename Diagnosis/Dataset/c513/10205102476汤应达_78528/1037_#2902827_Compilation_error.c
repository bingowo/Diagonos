#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{return *(long long*)b>*(long long*)a;}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    long long num[n],min=0,res;
    for(int i=0;i<n;i++) scanf("%lld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(int i=1;i<m;i++) min+=num[0]-num[i];
    res=min;
    for(int i=1;i<=n-m;i++)
    //从Number中的第二个元素开始，最多进行n-m次操作
    //因为每次要取出m个元素，所以i最大取到n-m
    {
         res = res - (number[i-1]-number[i])*(m-1)+(number[i]-number[i+m-1]);
        //number[i]之后的第m-1个元素与其差值一定最小
        //相当于替换最大的数
        if(res<min) min=res;
    }
    printf("%lld",min);
    
    return 0;    
}

