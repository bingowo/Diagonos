#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* l2a(long long num, char *str)
{
    int i = 0;//指示填充str
    if(num<0)//如果num为负数，将num变正
    {
        num = -num;
        str[i++] = '-';
    }
    //转换
    do
    {
        str[i++] = num%10+48;//取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0'
        num /= 10;//去掉最低位
    }
    while(num); //num不为0继续循环

    str[i] = '\0';

    //确定开始调整的位置
    int j = 0;
    if(str[0]=='-')//如果有负号，负号不用调整
    {
        j = 1;//从第二位开始调整
        ++i;//由于有负号，所以交换的对称轴也要后移1位
    }
    //对称交换
    for(; j<i/2; j++)
    {
        //对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i-1-j];
        str[i-1-j] = str[j] - str[i-1-j];
        str[j] = str[j] - str[i-1-j];
    }

    return str;//返回转换后的值
}

int is(long long int num)
{
    char a[100]= {"\0"};
    l2a(num,a);
    int len=strlen(a), flag=1;
    for(int i=0; i<=len/2; i++)
    {
        if(a[i]!=a[len-i-1])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    long long int num;
    int cnt=0;
    scanf("%lld",&num);
    while(is(num)==0)
    {
        char a[100]= {"\0"};
        l2a(num,a);
        int len=strlen(a);
        char b[len];
        for(int i=0; i<len; i++)
            b[i]=a[len-i-1];
        long long int tmp=atoi(b);
        num+=tmp;
        cnt++;
    }
    printf("%d %lld", cnt, num);


}
