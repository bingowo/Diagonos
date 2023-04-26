#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

//结果去前导0和后导0，先输入转化为 带分数的形式 再转化为三进制
//

long long int cmd(long long int a,long long int b)
{
    return (a%b == 0)?b:cmd(b,a%b);
}
//进行第二步的按位相加
//半加器，last为上一项的余位,judge控制加的是哪一位，1为整数位，0为小数位
int plus_half(long long int *i,long long int*dec,long long int last,int judge)
{
    if(judge)
    {
        *i= *i+1+last;
        if(*i>3||*i ==3 )
        {
          *i -= 3;
          return 1;
        }
    }
    else
    {
        *dec = *dec+1+last;
        if(*dec == 3||*dec >3)
        {
            *dec -= 3;
            return 1;
        }
    }
    return 0;


    }
void plus_(long long int *i,long long int*dec,int length_i,int length_dec)
{
    long long int next =0;
    for(int z =length_dec-1;z>-1;z--)
    {
         next = plus_half(i,&dec[z],next,0);
    }
    int p = 0;


        for(int z = length_i;z>0;z--)
        {
         next = plus_half(&i[z],dec,next,1);
        }
    if(next == 1)i[0] = 1;//i[0]为可能存在的最高位
    else i[0] = 0;
}
int main()
{
    long long int z, up,down;
    scanf("%lld%lld",&up,&down);
     int flag_dec = 0;//判断有无小数

    if(up%down)
    {
        flag_dec = 1;
    }
    z = up/down;
    up = up%down;
    long long int s_1[1500],s1[1500];//s1用于接收s_1的倒序
    memset(s_1,0,1500*sizeof(long long int));

    int length = 0;

    do
    {
        s_1[length++] =z%3;
        z /=3;
    }
    while(z!=0);//注意考虑z==0的情况
    for(int i =0;i<length;i++)
    {
        s1[i+1] = s_1[length - 1-i];
    }//空出s[1]中第一位为第二步做准备
    //小数
     int n =-1;
    long long int dec[1500];
    memset(dec,0,1500*sizeof(long long int));
    if(flag_dec)
    {
         long long int down_ = down;
         while(down_!=0)
         {
             down_/=3;
             n++;
         }//记录分母次数
         for(int i = n-1;i>-1;i--)
         {
             dec[n-i-1] = up/ (long long int)pow(3,i);
             up = up%(long long int)pow(3,i);
         }
    }

    plus_(s1,dec,length,n);
    for(int q =1;q < length + 1;q++)
    {
        s1[q] -=1;
    }
    for(int z =0;z<n;z++)
    {
        dec[z]-=1;
    }
    int point_int = 0;
    int point_dec;

    while(s1[point_int]==0)
    {
        point_int++;
    }
    for(point_dec = 1499;dec[point_dec] == 0;point_dec--);
    if(point_int!=1500)
    {
        for(int q =0;q <length+1;q++)
        {
            if(s1[q]==0&&q==0)continue;
            if(s1[q] == -1)s1[q]+=3;
            printf("%lld",s1[q]);
        }
    }
    else printf("0");
    if(flag_dec)
    {
        printf(".");
        for(int q= 0;q<point_dec+1;q++)
        {
            if(dec[q] == -1)dec[q]+=3;
            printf("%lld",dec[q]);
        }
    }


    //for(int o =0;o<length+1;o++)printf("%lld ",s1[o]);



    return 0;
}
