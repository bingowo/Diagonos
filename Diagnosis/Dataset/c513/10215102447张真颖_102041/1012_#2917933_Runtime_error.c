#include <stdio.h>
#include <stdlib.h>
#define N 10000000000000000000000000000000000000

char s[N]={0};
int main()
{
    long long qr=0,qi=0,r=0,a=0,b=0,jia=-1,jian1=-1,jian2=-1,si=-1,k=0;
    
    char sout[100]={0},ss[100]={0};
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='+') jia=i;
        else if(jian1==-1&&s[i]=='-') jian1=i;
        else if(s[i]=='-') jian2=i;
        else if(s[i]=='i') si=i;
    }
    if(jian1!=-1&&jian2==-1&&jia==-1) jian2=jian1,jian1=-1;
    if(jia!=-1)
    {
        for(int i=jian1+1;i<jia;i++)
            a=a*10+s[i]-'0';
    }
    else if(jian2!=-1)
    {
        for(int i=jian1+1;i<jia;i++)
            a=a*10+s[i]-'0';
    }
    else if(jia==-1&&jian2==-1&&si==-1)
    {
        for(int i=jian1+1;i<strlen(s);i++)
            a=a*10+s[i]-'0';
    }
    if(jian1!=-1) a=-a;
    if(si!=-1)
    {
        if(si==jia+1)
        {
            b=1;
        }
        else if(si==jian2+1)
        {
            b=-1;
        }
        else if(jia!=-1)
        {
            for(int i=jia+1;i<si;i++)
                b=b*10+s[i]-'0';
        }
        else
        {
            for(int i=jian2+1;i<si;i++)
                b=b*10+s[i]-'0';
            b=-b;
        }
    }
    if(a==0&&b==0) printf("0");
    else{
    while(!(a==0&&b==0))
    {
        if(a%2==0&&b%2==0||(a%2&&b%2)) r=0;
        else r=1;
        ss[k++]=r+'0';
        qr=-a+r+b;
        qi=-a+r-b;
        a=qr/2;
        b=qi/2;
    }
    k-=1;
    for(int i=0;k>=0;)
        sout[i++]=ss[k--];
    printf("%s",sout);
    }
    return 0;
}