#include<stdio.h>
#include<string.h>

int main()
{
    char num[50];scanf("%s",num);
    int rome[128],cnt=0;rome['I']=1,rome['V']=5;
    rome['X']=10,rome['L']=50,rome['C']=100;
    rome['D']=500,rome['M']=1000;
    long long stack[100],ans=0,flag=1;
    //依次处理数字并存入栈中
    for(int i=0;i<(int)strlen(num);i++)
    {
        switch (num[i])
        {
            case '(':flag*=1000;break;
            case ')':flag/=1000;break;
            default:stack[cnt++]=rome[num[i]]*flag;break;
        }
    }
    //左小减左，右小加右
    for(int i=0;i<cnt;i++)
    {
        if(stack[i]<stack[i+1] && i!=cnt-1) ans-=stack[i];
        else ans+=stack[i];
    }
    printf("%lld",ans);

    return 0;
}