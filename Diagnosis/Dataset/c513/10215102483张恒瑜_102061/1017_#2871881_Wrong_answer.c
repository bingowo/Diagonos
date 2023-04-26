#include<stdio.h>
#include<string.h>

int tr(char x)
{
    switch (x)
    {
        case 'I':return 1;break;
        case 'V':return 5;break;
        case 'X':return 10;break;
        case 'L':return 50;break;
        case 'C':return 100;break;
        case 'D':return 500;break;
        case 'M':return 1000;break;
        case '(':return 1000000;break;
        default:break;
    }
    return -1;
}

int main()
{
    char input[1000]={'\0'};
    scanf("%s",input);
    long long res=0,mult=1,tmp=0;
    int i;
    for(i=0;i<strlen(input);i++)
    {
        if(input[i]=='(')
        {
            res+=tmp;
            tmp=0;
            mult*=1000;
        }
        else if(input[i]==')')
        {
            res+=(tmp*mult);
            tmp=0;
            mult=1;
        }
        else
        {
            if(tr(input[i])<tr(input[i+1]) && (tr(input[i])==1 || tr(input[i])==10 || tr(input[i])==100)) tmp-=tr(input[i]);
            else tmp+=tr(input[i]);
        }
    }
    res+=tmp;
    printf("%lld",res);
    return 0;
}