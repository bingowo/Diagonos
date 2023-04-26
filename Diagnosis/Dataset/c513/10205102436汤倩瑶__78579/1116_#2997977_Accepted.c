#include<stdio.h>
long long int f(int x)
{
    long long int ans=1;
    for(int i=0;i<x;i++)
    {
        ans*=2;
    }
    return ans;
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    if(x<0)x=-x;
    if(y<0)y=-y;
    long long int dis=x+y;
    if(dis==0)printf("0");
    else if((dis%2)==0)printf("-1");
    else{
        int tmp=0;
        for(tmp=1;tmp<42;tmp++)
        {
            if(f(tmp-1)<=dis&&dis<=f(tmp))break;
        }
        printf("%d",tmp);

    }


return 0;
}
