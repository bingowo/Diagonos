#include<stdio.h>
#include<string.h>

void convert(long long d,char*res)
{
    int p=0;
    long long s=0,y=0;
    while(d!=0)
    {
        s=d/-2;
        y=d%-2;
        if(y<0)
        {
            s++;
            y-=(-2);
        }
        res[p++]=y+'0';
        d=s;
    }
    res[p]='\0';
}

int main()
{
    long long decimal;
    scanf("%lld",&decimal);
    if(decimal==0) printf("%c",decimal);
    else
    {
        char res[1001];
        convert(decimal,res);
        for(int i=strlen(res)-1;i>=0;i--) printf("%c",res[i]);
    }

    return 0;
}