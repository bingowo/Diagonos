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
    int j;
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
    for(i=l-1;s[i]!='.'&&i>=1;i--)
    {
        if(s[i]>='3'&&s[i-1]!='.')
        {
            s[i]=s[i]-3;
            s[i-1]=s[i-1]+1;
        }
    }
    if(s[i+1]>='3'&&s[i]=='.'&&i>=1)
    {
        s[i+1]=s[i+1]-3;
        s[i-1]=s[i-1]+1;
    }
    for(i=i-1;i>=1;i--)
    {
        if(s[i]>='3')
        {
            s[i]=s[i]-3;
            s[i-1]=s[i-1]+1;
        }
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
    s2[m]=0;i=0;
    if(s2[0]=='0')
    {
        if(s2[1]=='.');
        else
        {
            i=i+1;
            while(s2[i]!='.'&&s2[i])
        {
            if(s2[i]!='0')
                break;
            else
                i++;
        }
        }
        for(;s2[i]!='.'&&s2[i];i++)
            printf("%c",s2[i]);
    }
    else
    {
        for(i=0;s2[i]!='.'&&s2[i];i++)
            printf("%c",s2[i]);
    }
    int l2=strlen(s2)-1;
    if(s2[i]=='.')
    {
        printf("%c",s2[i]);
        for(;l2>i;l2--)
        {
            if(s2[l2]!='0')
                break;
        }
        for(i=i+1;i<=l2;i++)
            printf("%c",s2[i]);
    }
    return 0;
}
