#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void reverse(char s[])
{   int c,i,j;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];s[i]=s[j];s[j]=c;
    }
}
int main()
{
    int cnt1=0,cnt=0;
    int m2,r1,r=0,a,b,m,t,m1,l=0;
    char s[5000];
    for (int i=0; i<5000; i++)
    {
        s[i]='\0';
    }
    scanf("%d %d",&a,&b);
    m=a/b;m2=m;
    t=a%b;
    while(t>0)
    {
        m1=t%3;
        s[l++]=m1+'0';
        t=t/3;
        cnt++;
    }
    while (m>0)
    {
        m1=m%3;
        s[l++]=m1+'0';
        m=m/3;
    }
    for (int i=0; i<strlen(s); i++)
    {   r1=s[i];
        s[i]=(s[i]+1+r-'0')%3+'0';
        r=(r1+1+r-'0')/3;
    }
    cnt1=strlen(s)-1;
    if (r>0)
        s[strlen(s)]=r+'0';
    for (int i=0; i<=cnt1; i++)
    {
        s[i]=s[i]-1;
        if (s[i]=='0'-1)
            s[i]='2';
    }
     if (cnt>0)
     {for (int j=strlen(s);j>cnt;j--)
        s[j]=s[j-1];
        s[strlen(s)+1]='\0';

    s[cnt]='.';}
    if (m2==0)
        s[cnt+1]='0';
    while (s[0]=='0')
    {
        for (int j=0;j<strlen(s);j++)
        s[j]=s[j+1];
        s[strlen(s)-1]='\0';
    }
    reverse(s);
    printf("%s",s);

    return 0;
}
