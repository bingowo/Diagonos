#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void slo(char s[])
{
    int cnt1,r1,r=0;
    for (int i=0; i<strlen(s); i++)
    {
        r1=s[i];
        s[i]=(s[i]+1+r-'0')%3+'0';
        r=(r1+1+r-'0')/3;
    }
    cnt1=strlen(s)-1;
    if (r>0)
        s[strlen(s)]='0'+r;
    for (int i=0; i<=cnt1; i++)
    {
        s[i]=s[i]-1;
        if (s[i]=='0'-1)
            s[i]='2';
    }
}
void reverse(char s[])
{
    int c,i,j;
    for (i=0,j=strlen(s)-1; i<j; i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
int main()
{
    int cnt2=0,cnt=0;
    int a,b,m,t,m1,l=0;
    char s[500];
    for (int i=0; i<500; i++)
    {
        s[i]='\0';
    }
    scanf("%d %d",&a,&b);
    m=a/b;
    t=a%b;
    if (a>b)
    {
        if (t==0)
        {
            while (m>0)
            {
                m1=m%3;
                s[l++]=m1+'0';
                m=m/3;
            }
            slo(s);
            reverse(s);
            printf("%s",s);
        }
        else
        {
            while(t>0)
            {
                m1=t%3;
                s[l++]=m1+'0';
                t=t/3;
            }
            while (b!=1)
            {
                cnt++;
                b=b/3;
            }
            for (int i=strlen(s);i<cnt;i++)
                s[i]='0';
            while (m>0)
            {
                m1=m%3;
                s[l++]=m1+'0';
                m=m/3;
            }
            slo(s);
            for (int i=strlen(s);i>cnt;i--)
                s[i]=s[i-1];
            s[cnt]='.';
            reverse(s);
            while (s[strlen(s)]=='0')
                s[strlen(s)]='\0';
            printf("%s",s);
        }}
    else
    {
        while(t>0)
            {
                m1=t%3;
                s[l++]=m1+'0';
                t=t/3;
            }
            while (b!=1)
            {
                cnt++;
                b=b/3;
            }
            for (int i=strlen(s);i<cnt;i++)
                s[i]='0';
            s[strlen(s)]='0';
            slo(s);
            s[strlen(s)]= s[strlen(s)-1];
             s[strlen(s)-2]='.';
              reverse(s);
            while (s[strlen(s)]=='0')
                s[strlen(s)]='\0';
            printf("%s",s);
    }
    return 0;
}
