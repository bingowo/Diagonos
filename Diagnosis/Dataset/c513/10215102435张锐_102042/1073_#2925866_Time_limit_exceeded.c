#include <stdio.h>
#include <stdlib.h>
int miao(int x)
{
    if(x%9==0) return 0;
    else
    {
        int b=0;
        while(x)
        {
            if(x-(x/10)*10==9) {b=1;break;}
            x=x/10;
        }
        if(b==1) return 0;
        else return 1;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int num=0;
    for(int i=a;i<=b;i++)
    {
        if(miao(i)) num++;
    }
    printf("%d",num);
    return 0;
}
