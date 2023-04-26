#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000]={0},t[1000]={0};
    int a,b,c,x,carry=0,flag=0;
    scanf("%d %d",&b,&c);
    if(b<0) 
    {
    flag=1;
    a=-b/c;
    b=-b%c;
    }
    else 
    {
    a=b/c;
    b=b%c;
    }
    while(a!=0)
    {
        t[strlen(t)]=a%3+'0';
        a=a/3;
    }
    for(int i=strlen(t)-1;i>=0;i--) s[strlen(s)]=t[i];

    if(b!=0)
    {
        s[strlen(s)]='.';//小数部分
        while(b!=0)
        {
            x=0;
            b=3*b;
            while(b>=c)
            {
                b=b-c;x++;
            }
            s[strlen(s)]=x+'0';
        }
    }
    // printf("%s\n",s);


    if(flag)
    {
        for(int i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]=='.')   continue;
            x=1-(s[i]-'0')-carry;
            carry=x<0?1:0;
            s[i]=(x+3)%3+'0';
        }
    }
    else
    {
        for(int i=strlen(s)-1;i>=0;i--)//2
        {
            if(s[i]=='.')   continue;
            x=(s[i]-'0')+1+carry;
            s[i]=x%3+'0';
            carry=x/3;
        }
        if(carry)
        {
            for(int i=strlen(s)-1;i>=0;i--) s[i+1]=s[i];
            s[0]=carry+'0'+1;
        }
    }
    // printf("%s\n",s);

    for(int i=0;i<strlen(s);i++)//3
    {
        if(s[i]=='.')   continue;
        if(s[i]=='0') s[i]='2';
        else s[i]=s[i]-1;
    }


    int pa=0,pb=strlen(s)-1;//4
    while(s[pa]=='0')   pa++;
    if(strchr(s,'.')!=NULL)
    {
        while(s[pb]=='0')   pb--;//整数部分有问题
    }
    if(s[0]=='.')   printf("0");
    if(s[strlen(s)-1]=='.')  s[strlen(s)-1]==0;

    for(int i=pa;i<=pb;i++) printf("%c",s[i]);

}