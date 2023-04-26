#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[60]={'\0'};//存储罗马数字
    scanf("%s",s);
    int l,i,j;
    l=strlen(s);
    long long int a=0;//最后的数字
    int xishu=1;
    int b[128]={0};
    b['I']=1;b['V']=5;b['X']=10;b['L']=50;b['C']=100;b['D']=500;b['M']=1000;
    long long int number[60];//存储每个罗马数字代表的数字
    for(i=0,j=0;s[i];i++)
    {
        if(s[i]=='(')
        {
            xishu=xishu*1000;continue;
        }
        else
        {
            if(s[i]==')')
            {
                xishu=xishu/1000;continue;
            }
        }
        number[j]=b[s[i]]*xishu;//j是number的长度
        j++;
    }
    for(i=0;i<j-1;i++)
    {
        if(number[i]<number[i+1])
            number[i]=(-1)*number[i];
    }
    for(i=0;i<j;i++)
        a=number[i]+a;
    printf("%lld",a);
}
