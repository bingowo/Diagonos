    #include <stdio.h>
#include <string.h>
int main()
{
    char s[1000]={0},t[1000]={0};
    int a,b,c,x,carry=0;
    scanf("%d %d",&b,&c);
    a=b/c;
    b=b%c;
    while(a!=0)
    {
        t[strlen(t)]=a%3+'0';
        a=a/3;
    }
    for(int i=strlen(t)-1;i>=0;i--) s[strlen(s)]=t[i];
    s[strlen(s)]='.';
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
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='.')   continue;
        x=(s[i]-'0')+1+carry;
        s[i]=x%3+'0';
        carry=x/3;
    }
    if(carry)
    {
        for(int i=strlen(s)-1;i>=0;i++) s[i+1]=s[i];
        s[0]=carry+'0';
    }
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')   continue;
        if(s[i]=='0') s[i]='2';
        else s[i]=s[i]-1;
    }
    // printf("%s\n",s);
    int pa=0,pb=strlen(s)-1;
    while(s[pa]=='0')   pa++;
    while(s[pb]=='0')   pb--;
    for(int i=pa;i<=pb;i++) printf("%c",s[i]);

}