#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

//得到的1或0需要倒序输出

typedef struct comple
{
    long long int r, i;
}Complex;

//每次的转换
int reverse(Complex* c)
{
    int flag = 0;
    if ((c->r +c->i)%2)//一个启示，要尽量找到简单的逻辑关系
    {
        flag =1;
        c->r -=1;
    }
    long long int g;
    g = (-1)*(c->r + c->i)/2;
    c->r = (c->i - c->r)/2;
    c->i = g;
    return flag;//返回-1 +i进制下的数

}
int main()
{
    int *anwser =(int*)malloc(sizeof(int)*1e8);
    long long int point =0;//指向answer的位数
    Complex res;
    Complex* pres;
    pres = &res;
    res.i =0;
    res.r = 0;
    char p[45];
    scanf("%s", p);
    //注意，以下各种不确定
    long long int pre = 0;
    int sym = 1;
    int num_sym =0;
        for(int g = 0;g<strlen(p);g++)
        {
            if((p[g]>'0'-1)&&(p[g]<'9'+1))
            {
                pre*=10;
                pre += p[g]-'0';
            }
            if((g == strlen(p) - 1)&&(p[g] !='i'))
               {
                   res.r =sym*pre;
               }
            else if((p[g]=='+')||(p[g]=='-'))
            {
                if(g!= 0)//代表着实数位的结束
                {
                    res.r = sym*pre;
                    sym = 1;
                    pre = 0;
                }
                if(p[g]=='-')sym =-1;
            }
            else if(p[g] == 'i')//
                {
                if(g == 0){res.i =1;break;}
                else if(p[g-1] =='-'){res.i =-1;break;}
                else if(p[g-1]=='+'){res.i = 1;break;}
                else res.i = sym*pre;
            }
        }
    printf("%lld  %lld  ",res.r,res.i);
    while((res.r!=0)||(res.i!=0))
    {
    anwser[point] =reverse(pres);
    point++;
    }
    for(point -=1;point>-1;point--)
    {
        printf("%d",anwser[point]);
    }

    return 0;
}
