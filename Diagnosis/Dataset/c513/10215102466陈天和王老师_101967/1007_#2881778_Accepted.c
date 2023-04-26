#include <stdio.h>

int main()
{
    int i,t;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        long long c,a=1,p,maxsum=1,sum=1;

        scanf("%lld",&c);
        p=(c&a);
        while(c){
            c>>=1;
            if((c&a)!=p){
                sum++;
            }
            if( (c&a)==p || c==1){
                if(sum>=maxsum) maxsum=sum;
                sum=1;
            }
            p=(c&a);
        }
        printf("case #%d:\n",i);
        printf("%lld\n",maxsum);
    }
    return 0;
}

//进行位运算时你这个数据类型咋定义，比如64位32位，比如什么逻辑右移，算数右移