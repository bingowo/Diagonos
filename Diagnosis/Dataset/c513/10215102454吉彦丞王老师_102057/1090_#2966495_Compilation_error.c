#include<stdio.h>
int zhishu(int a)
{
    double c=a*(1.0);
    double b=a*(1.0);
    for(int i=0;i<a-1;i++)
    {
        b=b*c;
        while(b>=10)
        {
            b=b/10;
        }
    }
    return (int)b;
}
int main()
{
    while(1)
    {
        scanf("%d",&a);
        if(a==0)
        {
            break;
        }
        else if(a==1)
        {
            printf("%d\n",1);
        }
        else
        {
            printf("%d\n",zhishu(a));
        }
    }
    return 0;
}