
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#include<stdlib.h>
typedef long long int lli;
long long int GCD(long long int a,long long int b)
{
    if(b==0) return a;
	return GCD(b,a%b);
}


void Tfloat(lli a,lli b,char t[])
{
    lli x=1;
    int i=0;
    long long int r=GCD(b,a);
    a=a/r;
    b=b/r;
    while(a%b!=0)
    {
        b/=3;
        t[i++]=a/b+'0';
        a=a-(a/b)*b;
    }
}
void Tint(lli a,char s[])
{
    int i;
    if (a==0) s[0]='0';
    for (i=40;a&&i;a/=3)
    {
        s[i--]='0'+(a%3);
    }
    memmove(s,s+i+1,40-i);
    s[19-i+1]='\0';
    
}
void plus(char s[],int len)
{
    int temp=0,i=0,t=0;

    for(i=len-1;i>=0;i--)
    {
        if (s[i]=='.') continue;
        t=s[i]-'0'+1+temp;
        if (t>=3)
        {
            temp=1;
            s[i]=(t+'0'-3);
            (s[i]=='0')?(s[i]='2'):(s[i]=(int)s[i]-1);
        }
        else{
            temp=0;
            s[i]=t+'0';
            (s[i]=='0')?(s[i]='2'):(s[i]=(int)s[i]-1);
        }
        
    }
    if (temp) 
    {
        memmove(s+1, s ,len);
        s[len+1]='\0';
        s[0]='1';
    }
}
int main()
{
    lli ansi,ansj1,ansj2,A,B;
    int i;
    scanf("%lld %lld",&A,&B);
    char s[100]={0};
    char t[100]={0};
    ansi=A/B;//????
    if(ansi!=0) 
    {
        if(A%B==0) ansj1=0;
        else ansj1=A%B;
    }
    else 
    {
        s[0]='0';
        ansj1=A;
    }
    ansj2=B;
    Tint (ansi,s);
    Tfloat (ansj1,ansj2,t);
    strcat(s,".");
    strcat(s,t);

    plus(s,strlen(s));
    for (i=strlen(s)-1;i!='.';i--)
    {
        if(s[i]!='0') break;
        else s[i]='\0';
    }
    for (i=0;i<strlen(s);i++)
    {
        if(ansj1==0&&s[i]=='.') continue;
        printf("%c",s[i]);
    }
    system("pause");
    return 0;
}
