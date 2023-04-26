#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char* s)
{
    int i,j;
    char tmp;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

char pluss(char* s,char* s1)
{
    int i,c=0;
    char a='0';
    for (i=strlen(s)-1;i>=0;i--)
    {
        if (s[i]=='.') i--;
        if (i==0 && c==1) a='1';
        s[i]=s[i]+c+s1[i]-'0';
        if (s[i]=='3')
        {
            s[i]='0';
            c=1;
        }
        else if (s[i]=='4')
        {
            s[i]='1';
            c=1;
        }
        else c=0;

    }
    return a;
}

void minuss(char* s,char* s1)
{
    int i,c ;
    char a;
    for (i=strlen(s)-1;i>=0;i--)
    {
        if (s[i]=='.') i--;
        if (s[i]>=s1[i])
            s[i]=s[i]-(s1[i]-'0');
        else
            s[i]='2';
    }
}

void simp(char* s)
{
    int i;
    if (strchr(s,'.')==0) ;
    else
    {
        for (i=strlen(s)-1;s[i]=='0';i--) ;
            s[i+1]='\0';
        if (s[i]=='.') s[i]='\0';
    }
}

int main()
{
    long long a,b,x;
    scanf("%lld %lld",&a,&b);
    if (a==0) printf("%d\n",0);
    else
    {
        x=b;
        char s[100]={0}; char s1[100]={0};
        int i,j;
        for (i=0;b;i++)
            b=b/3;
        for (j=0;j<i-1;j++)
        {
            s[j]=a%3+'0';
            a=a/3;
        }
        if (x!=1)
        {
            s[j]='.';
            if (a==0) s[j+1]='0';
            for (i=0;a;i++)
            {
                s[++j]=a%3+'0';
                a=a/3;
            }
        }
        else
            for (i=0;a;i++)
            {
                s[j++]=a%3+'0';
                a=a/3;
            }


        reverse(s);
        for (i=0;s[i]=='0';i++)
            s1[i]='0';
        for (i;i<strlen(s);i++)
        {
            if (s[i]=='.') s1[i]='.';
            else
                s1[i]='1';
        }
    //    printf("%s\n",s);
    //    printf("%s\n",s1);
        char c=pluss(s,s1);
    //    printf("%s\n",s);
        minuss(s,s1);
        simp(s);
        if (c=='1' && strchr(s,'.')==0)
            printf("%c%s\n",c,s);
        else if (s[0]=='2')
            printf("%c%s\n",'1',s);
        else
            printf("%s\n",s);
    }
    return 0;
}
