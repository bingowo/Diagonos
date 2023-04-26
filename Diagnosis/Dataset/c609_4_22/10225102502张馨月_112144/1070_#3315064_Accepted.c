#include<stdio.h>
#include<stdlib.h>

int f(int n) 
{
    if(n==1) return 2;
    else if(n==2) return 4;
    else if(n==3) return 7;
    else return 2*f(n-1)-(f(n-2)-f(n-3));//!前n-3个字符串结尾为10要排除！
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        int ans=f(n);
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
