#include<stdio.h>

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    long long int i,S,num,min;
    if(x<y)
        min = x;
    else
        min = y;
    long long int W[min]={0};
    S=x*y;
    for(i=1;i<min+1;i++)
    {
        num = S/(i*i);
        W[i] = num*i*4;
    }
    long long int ans=W[1];
    for(i=1;i<min+1;i++)
    {
        if(W[i]>ans);
        else
            ans = W[i];
    }
    printf("%d\n",ans);
    return 0;
}
