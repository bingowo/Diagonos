#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[51];
    char c;
    int k=0;
    while((c=getchar())!=EOF && c!='\n')
            s[k++]=c;
    s[k]='\0';
    long long data[100];
    long long res=0;
    int cnt=0;
    long long flag=1;
    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;Roma['C']=100;
    Roma['M']=1000;Roma['D']=500;
    for(int i=0;s[i];i++)
    {
        switch(s[i])
        {
            case '(': flag=flag*1000;break;
            case ')':flag=flag/1000;break;
            default:data[cnt++]=Roma[s[i]]*flag;break;
        }
    }
    for(int i=0;i<cnt-1;i++)
    {
        if(data[i]<data[i+1])
            res-=data[i];
        else
            res+=data[i];
    }
    res+=data[cnt-1];
    printf("%lld",res);
    return 0;
}
