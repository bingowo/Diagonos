#include<stdio.h>
#include<string.h>
long long RE(char s[],long long start,long long end)//求实部函数
{
    long long result;
    for(long long i=start;i<=end;i++)
    {
        result*=10;
        result+=s[i];
    }
    return result;
}
int main(void)
{
    char s[100]={0};//存输入
    gets(s);
    long long int im=0,re=0,con=1;
    long long int len=strlen(s);
    for(long long int i=0;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9') s[i]=s[i]-'0';//实部数字确认
    }
    if(s[len-1]=='i')//有虚部时：
    {
        if(s[len-2]=='+' || '-')
        {
            if(s[len-2]=='+') im=1;
            if(s[len-2]=='-') im=-1;
            if(len-2!=0)//有+-时求前面的实部
            {
                if(s[0]=='+') re=RE(s,0,len-3);
                else re=-RE(s,1,len-3);//跳过-，1开始
            }
        }
        else//只有虚部
        {
            for(long long j=len-1;j>=0;j--)
            {
                
            }
        }
    }
    return 0;
}