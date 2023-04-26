#include<stdio.h>

typedef struct {long long int sum,x,y;} A;

long long int max1(long long int a, long long int b)
{
    if(a>b)return a;
    else return b;
}

long long int absm(long long int a, long long int b)
{
    if((a-b)<0)return b-a;
    else return a-b;
}

int main()
{
    long long int x,y;
    scanf("%d %d",&x,&y);
    int count;long long int max=9999999999,x1=9999999999,y1=9999999999,temp1,temp2;
    scanf("%d",&count);
    A D;
    while(count--)
    {
        scanf("%lld %lld",&D.x,&D.y);
        temp1=absm(x,D.x);
        temp2=absm(y,D.y);
        D.sum=max1(temp1,temp2);
        if(D.sum<max)
        {
                x1=D.x;
                y1=D.y;
                max=D.sum;
        }
        else if(D.sum==max)
        {
            if(D.x<x1)
            {
                x1=D.x;y1=D.y;
            }
            else if(D.x==x1)
            {
                if(D.y<y1)y1=D.y;
            }

        }
        //printf("%lld %lld\n",D.x,D.y);
    }
    printf("%lld\n",max);
    printf("%lld %lld",x1,y1);
}
