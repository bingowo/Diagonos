#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void itob(int n,char *s,int r)
{
    const char table[]={"0123456789ABCDEF"};
    int sigh=1,m=0;
    if(n<0)
    {
        sigh=-1;
        n=-n;
    }
    do
    {
        *(s+m)=table[n%r];
        n=n/r;
        m+=1;
    }
    while(n);
    if(sigh==-1)
    {
        *(s+m)='-';
        *(s+m+1)=0;
        for(int i=0;i<m/2+1;i++)
        {
            int temp=*(s+i);*(s+i)=*(s+m-i);*(s+m-i)=temp;
        }
    }
    else
    {
        *(s+m)=0;
        for(int i=0;i<m/2;i++)
        {
            int temp=*(s+i);*(s+i)=*(s+m-i-1);*(s+m-i-1)=temp;
        }
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,r;
        char s[100],*ps;
        char result[100],*pr;
        scanf("%d %d",&n,&r);
        ps=&s[0];
        pr=&result[0];
        itob(n,ps,r);
        int len=strlen(s);
        int sum=0;
        for(int j=0;j<len;j++)
        {
            if(s[j]=='A') sum+=10;
            else if(s[j]=='B') sum+=11;
            else if(s[j]=='C') sum+=12;
            else if(s[j]=='D') sum+=13;
            else if(s[j]=='E') sum+=14;
            else if(s[j]=='F') sum+=15;
            else sum=sum+(s[j]-'0');
        }
        itob(sum,pr,r);
        printf("case #%d:\n%s\n",i,result);
    }
    return 0;
}
