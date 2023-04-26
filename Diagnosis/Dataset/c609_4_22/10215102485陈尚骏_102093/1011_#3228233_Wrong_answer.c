#include <stdio.h>
#include <stdlib.h>
#include<string.h>

long GCD(long a,long b)
{
    if(b%a==0) return a;
    else return GCD(b%a,a);
}

void dlt(char*s)
{
    long ansA=0;
    int len=strlen(s);
    for(int i=0;i<len;++i)
    {
        ansA*=3;
        if(s[i]=='1') ansA++;
        if(s[i]=='2') ansA--;
    }
    printf("%ld",ansA);
}

void dldb(char*s)
{
    long ansA=0,ansB=0,ansC=1;
    int len=strlen(s),flag;
    for(int i=0;i<len;++i)
    {
        if(s[i]=='.') flag=i;
    }
    for(int i=0;i<flag;++i)
    {
        ansA*=3;
        if(s[i]=='1') ansA++;
        if(s[i]=='2') ansA--;
    }
    for(int i=flag+1;i<len;++i)
    {
        ansB*=3;
        ansC*=3;
        if(s[i]=='1') ansB++;
        if(s[i]=='2') ansB--;
    }
    if(!ansA&&ansB<0)
    {
        ansB+=ansC;
        ansA--;
    }
    else if(ansB>0&&ansA<0)
    {
        ansA++;
        ansB=ansC-ansB;
    }
    long c=ansC/GCD(ansC,ansB);
    long b=ansB/GCD(ansC,ansB);
    if(c<0)
    {
        c=-c;
        b=-b;
    }
    if(ansA==0)  printf("%ld %ld",b,c);
    else printf("%ld %ld %ld",ansA,b,c);
}

int main()
{
    char s[31];
    memset(s,0,31);
    scanf("%s",s);
    if(strchr(s,'.')==0) dlt(s);
    else dldb(s);
    return 0;
}
