#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
char s[10005];

int check(int a,int b,int x,int y,int dx,int dy)
{
    if(dx==0) //坐标在y轴方向移动
    {
        if(dy==0) //坐标在x轴方向移动
        {
            if(x==a && b==y)
                return 1;
        } //原地不动
        else //在y轴方向滑动
        {
            if(x==a && (b-y)%dy==0 && (b-y)/dy>=0) //符合要求，要大于0
                return 1;
        }
    }
    else if(dy==0)
    {
        if( b==y && (a-x)%dx==0 && (a-x)/dx>=0)
            return 1;
    }
    else if((a-x)%dx==0&&(b-y)%dy==0&&(a-x)/dx==(b-y)/dy && (a-x)/dx>=0) //注意x轴和y轴的差量是相同整数倍
        return 1;
    return 0;
}

int main()
{
    int x=0,y=0,dx,dy,a,b;
    scanf("%s",s);
    //先计算经过一轮的结果
    for(int i=0;s[i];i++)
    {
        if(s[i]=='U')
            y++;
        else if(s[i]=='D')
            y--;
        else if(s[i]=='R')
            x++;
        else
            x--;
    }
    dx=x;
    dy=y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        int f=0;  //flag
        x=y=0;
        if(check(a,b,x,y,dx,dy))
            f=1;
        for(int j=0;s[j];j++)
        {
            if(s[j]=='U')
                y++;
            else if(s[j]=='D')
                y--;
            else if(s[j]=='R')
                x++;
            else
                x--;
            if(check(a,b,x,y,dx,dy))
                f=1;
        }//
        
        if(f==0)
            puts("No");
        else
            puts("Yes");
        
    }
    return 0;
}
//整体的算法是
//先得到一整个步骤的移动总量
//再对于每一个小步加上移动总量的整数倍
//进行判断
