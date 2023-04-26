#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


//接收，逐位相加，分数最简
//分数位的进位问题
long long int cmd(long long int a,long long int b)
{
    return (a%b ==0)?b:cmd(b,a%b);
}
int a[4] = {0,1,-1};
int main()
{


    char s[1500];
    scanf("%s",s);
    int flag = 0;//判断是否是小数位
    long long int z =0,up,down =1;
    up =0;
    for(int i =0;i < strlen(s);i++)
    {
        if(s[i] == '.')
        {
            flag = 1;
            continue;
        }
           int num = a[s[i]-'0'];
        if(flag)
        {
            down *= 3;
            up *= 3;
            up += num;
        }
        else
        {
            z *= 3;
            z += num;
        }
    }
    //处理进位问题
    if(up == 0)
    {
        printf("%lld",z);
    }
    long long int t = cmd(down,up);
    else if(up < 0)
    {
        if(!(z<0))
        {
            z -=1;
         up/=t ;
        down/= t;
        up = down + up;}
        else
        {
            up = (-1)*up;
            down  /=t;
            up /=t;

        }
        printf("%lld %lld %lld",z,up,down);
    }
    else if(up > 0&&!(z > 0))
    {
        z+=1;
          up/=t;
        down/=t;
        up = down -up;
        printf("%lld %lld %lld",z,up,down);
    }
    else
    {

        up/=t ;
        down/=t;
        printf("%lld %lld %lld",z,up,down);
    }
    return 0;
}
