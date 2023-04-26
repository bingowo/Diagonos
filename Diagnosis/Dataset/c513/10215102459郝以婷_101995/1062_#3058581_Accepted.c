#include <stdio.h>
#include <stdlib.h>

long long int Tb[51]={0,1,2,4,8};

long long re(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else if(n==4)
        return 8;
//    else
//        return re(n-1)+re(n-2)+re(n-3)+re(n-4);//超时了，要做个数组，比如算50级台阶，就把前四十九级都记下来
    else
    {
        long long t1=(Tb[n-1]==0?re(n-1):Tb[n-1]);
        long long t2=(Tb[n-2]==0?re(n-2):Tb[n-2]);
        long long t3=(Tb[n-3]==0?re(n-3):Tb[n-3]);
        long long t4=(Tb[n-4]==0?re(n-4):Tb[n-4]);
        long long ans=t1+t2+t3+t4;
        Tb[n]=ans;
        return ans;
    }
}

int main()
{
    int T,i,n;
    long long ret;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        ret=re(n);
        printf("case #%d:\n",i);
        printf("%lld\n",ret);
    }
    return 0;
}
