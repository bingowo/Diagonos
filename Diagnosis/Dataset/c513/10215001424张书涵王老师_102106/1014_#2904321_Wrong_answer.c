#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(char* s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    int a,b;
    char s2[1000];
    scanf("%d %d",&a,&b);
    if(a==0)
    {
        printf("0");
        return 0;
    }
    int n;
    n=a/b;
    a=a%b;
    char s[1000];
    int i=0;
    if(n==0)
    {
        s[i++]='0';
    }
    else
    {
        for(i=0;n>0;i++)
    {
        s[i]=n%3+'0';
        n=n/3;
    }
    s[i]=0;
    reverse(s);
    }
    int k;
    k=log(b)/log(3);
    if(a==0);
    else
    {
        s[i]='.';
        int j;
        for(j=i+k;j>i;j--)
            {
                s[j]=a%3+'0';
                a=a/3;
            }
    }
    int l;
    l=strlen(s);
    for(i=0;s[i];i++)
    {
        if(s[i]=='.');
        else
            s[i]=s[i]+1;
    }
    for(i=l-1;s[i]>='3'&&s[i-1]!='.'&&i>=1;i--)
    {
        s[i]=s[i]-3;
        s[i-1]=s[i-1]+1;
    }
    if(s[i]>='3'&&s[i-1]=='.'&&i>=1)
    {
        s[i]=s[i]-3;
        s[i-2]=s[i-2]+1;
    }
    for(i=i-2;i>=1&&s[i]>='3';i--)
    {
        s[i]=s[i]-3;
        s[i-1]=s[i-1]+1;
    }
    int m=0;
    if(s[0]>='3')
    {
        s2[m++]='1';
        s[0]=s[0]-3;
    }
    for(i=0;s[i];i++)
    {
        if(s[i]=='.');
        else
        {
            s[i]=s[i]-1;
            if(s[i]==47)
                s[i]='2';
        }
    }
    for(i=0;s[i];i++,m++)
        s2[m]=s[i];
    s2[m]=0;
    for(i=0;s2[i];i++)
        printf("%c",s2[i]);
}

