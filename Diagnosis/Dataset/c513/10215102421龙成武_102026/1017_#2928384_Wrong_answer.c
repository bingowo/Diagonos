#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int changedigit(char *p);
long long int sumupdigit(char *p);

int main()
{
    char c[55];
    char *p;
    long long int res=0;

    c[0]='(';
    scanf("%s",c+1);
    p=c+strlen(c);
    *p++=')';
    *p--=0;             //p指向最后一个括号
    p--;                //p指向第一个有效值


    res=sumupdigit(p);
    printf("%lld",res);
    return 0;
}
int changedigit(char *p)            //传入一个字符指针，返回一个罗马数字对应的十进制数值
{
    int temp1;
    switch(*p)
    {
    case 'I':
        temp1=1;break;
    case 'V':
        temp1=5;break;
    case 'X':
        temp1=10;break;
    case 'L':
        temp1=50;break;
    case 'C':
        temp1=100;break;
    case 'D':
        temp1=500;break;
    case 'M':
        temp1=1000;break;
    }
    return temp1;
}
long long int sumupdigit(char *p)             //传入一个结构体指针，
{
    long long int res,temp1,temp2;
    res=temp1=temp2=0;

    while(*p!='(')                  //不为左括号时，始终循环计算括号里的值
    {
        if(*p==')')                      //如果为右括号，则进行递归
        {
            res+=1000*sumupdigit(p-1);
        }
        //底下其实都是else（非递归）的部分
        temp1=changedigit(p);
        if(temp1!=temp2)
        {
            if(res<=temp1)
            {
                res+=temp1;
            }
            else
            {
                res-=temp1;
            }

        }
        else
        {
            res+=temp1;
        }
        temp2=temp1;
        p--;
    }

    return res;
}
