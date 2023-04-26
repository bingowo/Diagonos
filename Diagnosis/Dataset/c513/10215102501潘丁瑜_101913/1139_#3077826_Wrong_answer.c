#include <stdio.h>
#include <stdlib.h>
int judge(int x)
{
    while(x > 0)
    {
        if(x%10 == 0 || x%10 == 1)
            x/=10;
        else return -1;
    }
    return 1;

}
int main()
{
    int i=0,n;
    int temp,flag=0;
    scanf("%d",&n);
    for(i=1;i<=1000;i++)
    {
        temp = n*i;
        flag = judge(temp);
        if(flag == 1)
        {
            printf("%d",temp);
            break;
        }
    }
    if(flag == -1) printf("-1");
    return 0;
}
