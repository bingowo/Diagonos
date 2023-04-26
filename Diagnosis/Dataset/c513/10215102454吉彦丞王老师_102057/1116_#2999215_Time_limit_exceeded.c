#include<stdio.h>
#include<math.h>
int num(int a,int b)
{
    int t=abs(a)+abs(b);
    int re=0;
    while(t>0)
    {
        re++;
        t=t/2;
    }
    return re;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==0&&b==0)
    {
        printf("0");
    }
    else
    {
        if((abs(a)+abs(b))%2==0)
        {
            printf("-1");
        }
        else
        {
            printf("%d",num(a,b));
        }
    }
    return 0;
}