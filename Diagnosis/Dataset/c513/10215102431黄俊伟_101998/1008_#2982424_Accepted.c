#include <stdio.h>
#include <stdlib.h>

int f(int,int);
int main(void)
{
    int T,x,y,ans;
    scanf("%d",&T);
    getchar();
    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &x, &y);
        getchar();
        ans=f(x,y);
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}

int f(int num1, int num2)
{
    int count=0,x,y;
    x=num1;y=num2;
    while(x!=0||y!=0)
    {
        count+=((x%2)==(y%2))?0:1;
        x/=2;
        y/=2;
    }
    return count;
}