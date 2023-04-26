#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[128]={['I']=1,['V']=5,['X']=10,['L']=50,['C']=100,['D']=500,['M']=1000};

int main()
{
    char s[60];scanf("%s",s);
    long long data[100];
    long long flag=1;
    int cnt=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        switch(s[i])
        {
            case '(': flag=flag*1000;break;//出现括号，变为原来的1000倍，括号里面的都变为原来的1000倍
            case ')': flag=flag/1000;break;//所以可以分别变为1000倍
            default: data[cnt++]=a[s[i]]*flag;break;//没有括号就不变
        }
    }
    long long ans=0;
    for(int i=0;i<cnt-1;i++)
    {
        if(data[i]<data[i+1])//左面比右面小，减掉
            ans-=data[i];
        else ans+=data[i];
    }
    ans+=data[cnt-1];//数组始终是一个个比的，元素没有改变，改变的是ans值
    printf("%lld\n",ans);
}
