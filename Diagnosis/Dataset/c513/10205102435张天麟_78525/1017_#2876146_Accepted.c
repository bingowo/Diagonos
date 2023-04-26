#include<stdio.h>
#include<string.h>
char s[50];
long long ans[50];
int main()
{
    int i=0,j=0;
    long long num=0,k=1;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
        {
            k*=1000;
        }
        else if(s[i]==')')
        {
            k/=1000;
        }
        else
        {
            if(s[i]=='I')ans[j]=k;
            else if(s[i]=='V')ans[j]=k*5;
            else if(s[i]=='X')ans[j]=k*10;
            else if(s[i]=='L')ans[j]=k*50;
            else if(s[i]=='C')ans[j]=k*100;
            else if(s[i]=='D')ans[j]=k*500;
            else ans[j]=k*1000;
            j++;
        }
    }
    for(i=0;i<j-1;i++)
    {
        if(ans[i]<ans[i+1])
        {
            num+=ans[i+1]-ans[i];
            i++;
        }
        else
        {
            num+=ans[i];
        }
    }
    num+=ans[i];
    printf("%lld",num);
    return 0;
}