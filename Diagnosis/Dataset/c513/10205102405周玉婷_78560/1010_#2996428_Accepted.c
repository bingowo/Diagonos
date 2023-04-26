#include <stdio.h>
#include <string.h>

void atob(int num,char s[])
{
    int i,len=0;
    for( i=18; num!=0 ; num/=2)//转换为二进制，对s[]20，从是s[18]开始逆序输入到s，是s[19]置'\0'
    {
        s[i--] = num%2 + '0';
        len++;//记录长度
    }
    s[19]=0;
    memmove(s,s+i+1,len+1);//将结尾的'\0'也复制过去，用于输出二进制码
}

void printbit(char s[], int length)
{
    int len=strlen(s);
    if(len<length)
    {
        for(int i=0; i<length-len; i++)
        printf("%c",'0');
    }
    printf("%s",s);//即temp，但在二进制码后已有结束符，故可输出正确二进制码
}

int main()
{
    char s[502],temp[20];//由题意每三位数一存，最大三位数999，二进制为10位，故用于存储二进制的temp开了20
    scanf("%s",s);
    int len=strlen(s);
    int tempnum=0;
    printf("0001");
    atob(len,temp);
    printbit(temp,10);
    for(int i=0; i<len; i++)//三三分
    {
        tempnum=tempnum*10+s[i]-'0';//霍纳原则计算，将三位数换为整数
        if(i%3==2) //每三位一分，注意i从0开始
        {
        atob(tempnum,temp);//把二进制码放到temp中
        printbit(temp,10);
        tempnum=0;
        }
    }
    if(len%3==1)
    {
        atob(tempnum,temp);
        printbit(temp,4);
    }
    if(len%3==2)
    {
        atob(tempnum,temp);
        printbit(temp,7);
    }
    return 0;
}