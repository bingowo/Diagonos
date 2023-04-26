
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
    a=a/GCD(b,a);b=b/GCD(b,a);
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
    for (i=19;a&&i;a/=3)
    {
        s[i--]='0'+(a%3);
    }
    memmove(s,s+i+1,19-i);
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
            (s[i]=='0')?s[i]='2':s[i]=(int)s[i]-1;
        }
        else{
            temp=0;
            s[i]=t+'0';
            (s[i]=='0')?s[i]='2':s[i]=(int)s[i]-1;
        }
    }
    printf("%s",s);
}
int main()
{
    long long int ansi,ansj1,ansj2,A,B;
    scanf("%lld%lld",&A,&B);
    char s[50]={0};
    char t[50]={0};
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
    // printf("%lld %lld\n",ansj1,ansj2);
    Tfloat (ansj1,ansj2,t);
    strcat(s,".");
    strcat(s,t);
    plus(s,strlen(s));
    // printf("%s\n",t);
    // printf("%s %d",s,strlen("2"));

    return 0;
}
