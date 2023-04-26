#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
typedef long long int lli;

lli tolli(char* s)
{
    int len = strlen(s);
    lli sum = 0;
    for(int i=0; i<len; i++)
    {
       sum = sum*10 + s[i] - '0';
    }
    return sum;
}

void Change(lli rel, lli img)
{
    char res[300];
    int remain, index=0;
    if(abs(rel)%2==0 && abs(img)%2==0)  remain = 0;
    else if(abs(rel)%2==1 && abs(img)%2==1) remain = 0;
    else remain = 1;
    res[index++] = remain+'0';//判断余数，保存
    if(remain == 1) rel-=1;
    int temp;
    while(rel!=0 || img!=0)
    {
        temp = -1*img;
        temp*=(-1);
        img = -1*img +(-1*rel);
        rel = -1*rel+temp;//计算(rel + img*i)/(-1 + i)=(rel + img*i)*(-1-i)/2的分子的rel系数
        rel/=2; img/=2;//上条注释的分母2
        if(abs(rel)%2==0 && abs(img)%2==0)  remain = 0;
        else if(abs(rel)%2==1 && abs(img)%2==1) remain = 0;
        else remain = 1;
        res[index++] = remain+'0';//保存余数
        if(remain == 1) rel-=1;//去除余数后的被除数
    }
    for(int i=index-1; i>=0; i--)
    {
        printf("%c",res[i]);
    }
    printf("\n");
    return ; 
}

int main()
{
    char s[50], temp[30];
    scanf("%s", s);
    int len = strlen(s), index = 0, flag = 1;//flag=1，为读取实部；flag=2表示读取虚部
    lli rel, img, sign_1 = 1, sign_2 = 1;//实部，虚部，实部符号，虚部符号
    if(s[0] == '-') sign_1 = -1;
    for(int i=0; i<len; i++)
    {
        if(flag==1 && isdigit(s[i])) 
        temp[index++] = s[i];
        else if(flag==1 && (i!=0 ||s[0]='i'))//除第一个元素外，第一次读取到不是数字的字符
        {
            temp[index] = '\0';
            lli number = tolli(temp) * sign_1;//实部读取完毕
            if(s[i] == '+') {rel = number; flag =2;index = 0;}//有+ -号，实数读取完毕，准备读取虚部，设flag=2
            else if(s[i] == '-') {rel = number; sign_2 = -1;flag = 2;index = 0;}//同上
            else if(s[i] == 'i') //只有虚部
            {
            if(index == 0) img = 1*sign_1;
            else img = number;
            rel = 0;
            }
        }
        
        if(i == len-1 && isdigit(s[i]))//只有实数部分
        { 
        temp[index] = '\0';
        lli number_1 = tolli(temp) * sign_1;
        rel = number_1; img = 0;
        }
        if(flag==2 && isdigit(s[i]))//（有实部也有虚部）读取虚部
        temp[index++] = s[i];
        else if(flag==2 && s[i] == 'i')
        {;
            lli number_2;
            if(index == 0)  number_2 = 1*sign_2;
            else
            {
            temp[index] = '\0';
            number_2 = tolli(temp) * sign_2;
            }
            img = number_2;
        }
    }
    Change(rel, img);
    return 0;
}