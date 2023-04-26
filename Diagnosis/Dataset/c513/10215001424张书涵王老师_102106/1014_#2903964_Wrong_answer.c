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
    int i;
    for(i=0;n>0;i++)
    {
        s[i]=n%3+'0';
        n=n/3;
    }
    s[i]=0;
    reverse(s);
    int k;
    k=log(b)/log(3);
    s[i]='.';
    int j;
    for(j=i+k;j>i;j--)
    {
        s[j]=a%3+'0';
        a=a/3;
    }
    int l;
    l=strlen(s);
    s[l-1]=s[l-1];
    for(i=0;s[i];i++)
    {
        if(s[i]=='.');
        else
            s[i]=s[i]+1;
    }
    for(i=l-1;s[i]>='3'&&s[i-1]!='.';i--)
    {
        s[i]=s[i]-3;
        s[i-1]=s[i-1]+1;
    }
    if(s[i]>='3'&&s[i-1]=='.')
    {
        s[i]=s[i]-3;
        s[i-2]=s[i-2]+1;
    }
    for(i=i-2;i>=1&&s[i]>='3';i--)
    {
        s[i]=s[i]-3;
        s[i-1]=s[i-1]+1;
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
    for(i=0;s[i];i++)
        printf("%c",s[i]);
}
