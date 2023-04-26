#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char s[1005];
int p[10];

int cal(int x)
{
    return x*x*x*p[3]+x*x*p[2]+x*p[1]+p[0];
}

int main()
{
    while(~scanf("%s",s))
    {
        int res=0,flg=1; //flg初始为1，可以代表默认的正号
        p[0]=p[1]=p[2]=p[3]=0;
        //读入函数
        //关键步骤
        for(int i=5;s[i];i++)
        {
            if(s[i]=='+')
                flg=1;
            else if(s[i]=='-')
                flg=-1;
            else if(s[i]>='0'&&s[i]<='9')
            {
                res=res*10+s[i]-'0';
                if(s[i+1]==0) //常数项结束方式
                    p[0]=res*flg;
            }
            else if(s[i]=='x')
            {
                if(res==0) //第一项系数是1或-1的情况
                    res=1;
                if(s[i+1]!='^') //对于一次项的特殊处理
                    p[1]=res*flg;
                else
                {
                    p[s[i+2]-'0']=res*flg;
                    i+=2; //跳过指数的处理
                }
                //重新初始化
                res=0;
                flg=1;
            }
        }
//        printf("%d %d %d %d\n",p[0],p[1],p[2],p[3]);
        for(int i=20;i>=-20;i--)
        {
            for(int j=-20;j<=20;j++)
            {
                if(i==cal(j))
                    putchar('*'); //优先级最高
                else if(i==0)
                {
                    if(j==0) //原点
                        putchar('+');
                    else if(j<20) //X轴
                        putchar('-');
                    else
                        putchar('>'); //横向
                }
                else if(j==0)
                {
                    if(i==20)
                        putchar('^'); //纵向
                    else
                        putchar('|'); //Y轴
                }
                else
                    putchar('.'); //优先级最低
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
//难题
//1、读入函数
//2、描绘坐标系
