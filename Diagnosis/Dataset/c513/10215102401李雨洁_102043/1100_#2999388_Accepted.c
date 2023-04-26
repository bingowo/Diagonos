#include <stdio.h>
#include <string.h>

struct point
{
    int a;
    int b;
};

int solution(int t,int r) //单个方程求解m
{
    if(t == 0 && r != 0) //无解
        return -2;
    if(t == 0 && r == 0) //任意解
        return -1;
    if(r % t != 0 || r / t < 0) //解为负数或非整数，非法解
        return -2;
    return r/t;
}

int main()
{
    struct point pos[200];
    char s[200];
    scanf("%s",s);
    int len = strlen(s);
    pos[0].a = 0;
    pos[0].b = 0; //记录起始位置(0,0)
    for(int i = 1; i <= len; i++) //记录第一轮命令序列经过的每一个位置点
    {
        switch(s[i-1])
        {
            case 'U':
                pos[i].a=pos[i-1].a;
                pos[i].b=pos[i-1].b+1;
                break;
            case 'D':
                pos[i].a=pos[i-1].a;
                pos[i].b=pos[i-1].b-1;
                break;
            case 'L':
                pos[i].a=pos[i-1].a-1;
                pos[i].b=pos[i-1].b;
                break;
            case 'R':
                pos[i].a=pos[i-1].a+1;
                pos[i].b=pos[i-1].b;
                break;
        }
    }
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q; i++)
    {
        int flag = 0;
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j = 0; j <= len; j++)
        {
            int m1 = solution( -pos[len].a, pos[j].a-a); //求解第一个方程m1
            int m2 = solution( -pos[len].b, pos[j].b-b); //求解第二个方程m2
            if (m1 == -2||m2 == -2)
            {
                continue; //无解情况
            }
            else if (m1 == -1||m2 == -1||m1 == m2) //判断两坐标轴的解是否相同
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

