#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//第一轮结束后的位置点（x0.y0）
struct point
{    int a,b; };
struct point pos[200];
//x(最终)=(第一轮中的每一个点横坐标)+mx0(第一轮结束的点的横坐标)
//（pos[i]-a）-x(最终)(即a)=-mx0（即pos[len].a）;
//r                        =m       t
int solution(int t,int r)                 //单个方程求解m
{
    if (t==0&&r!=0) return -2;          //无解
    if (t==0&&r==0) return -1;           //任意解
    if (r%t!=0||r/t<0) return -2;           //解为负数或非整数，非法解
    return r/t;                                      //返回解
}

int main()
{
    char s[200];

    scanf("%s",s);//输入命令
    int t;
    scanf("%d",&t);
    for(int p;p<t;p++){
    int len=strlen(s);//循环节的长度
    pos[0].a=0;pos[0].b=0;   //记录起始位置(0,0)
    int flag=0;
    for(int i=1;i<=len;i++)        //记录第一轮命令序列经过的每一个位置点
    {
        switch(s[i-1])
        {
        case 'U':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b+1;break;
        case 'D':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b-1;break;
        case 'L':pos[i].a=pos[i-1].a-1;pos[i].b=pos[i-1].b;break;
        case 'R':pos[i].a=pos[i-1].a+1;pos[i].b=pos[i-1].b;break;
        }
    }

         flag=0;
         int a,b,m1,m2;
         scanf("%d%d",&a,&b);//目标点
         for(int j=0; j<=len; j++)
        {
            m1=solution(-pos[len].a,pos[j].a-a);      //求解第一个方程m1，判断m1是否有解
            m2=solution(-pos[len].b,pos[j].b-b);      //求解第二个方程m2，判断m2是否有解
            if (m1 == -2||m2 == -2) continue;     //无解情况，其中 一个无解就是无解
            if (m1 == -1||m2 == -1||m1 == m2)      //判断两坐标轴的解是否相同,或有一解是无穷解（因为无解的情况上文已排除，有一个是无穷解，另外一个一定有解）
            {   flag=1;  break;  }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }


}