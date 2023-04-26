#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(long int a,long int b,char s[])
{
    long int m=a/b,n=a%b,i,j;
    char ss[10000];
    for(i=0;m>0;i++)
    {
        ss[i]=m%3+'0';
        m/=3;
    }
    i-=1;
    for(j=0;i>=0;)
        s[j++]=ss[i--];
    for(int t=j;n>0;j++)
    {
        if(t==j)
        {
            s[j]='.';
        }
        else
        {
            s[j]=n*3/b+'0';
            n=(n*3)%b;
        }

    }
    s[j]=0;
}

void add_sub(char s[])
{
    int len=strlen(s),len2;
    int carry=0,i,tmp;
    char ss[10000];
    for(i=len-1;i>=0;i--)
    {
        if((s[i]-'0'+1+carry)>=3)
        {
               tmp=carry;
               carry=(s[i]-'0'+carry+1)/3;
               s[i]=s[i]+1+tmp-carry*3;
        }
        else if(s[i]=='.') s[i]='.';
        else
        {
            s[i]=s[i]+1+carry;
            carry=0;
        }
    }
    if(carry)
    {
         ss[0]=carry+'0';
         ss[1]=0;
         for(int j=1,i=0;j<len+1;j++,i++)
            ss[j]=s[i];
         strcpy(s,ss);
    }
    len2=strlen(s);
    for(i=strlen(s)-1;i>=(len2-len);i--)
    {
        if(s[i]-1-'0'==-1) s[i]='2';
        else if(s[i]=='.') s[i]='.';
        else
            s[i]=s[i]-1;

    }
    if(s[0]=='.')
    {
        ss[0]='0',ss[1]=0;
        strcat(ss,s);
        strcpy(s,ss);
    }
}
int main()
{
    long int A,long int B;
    char s[10000];
    scanf("%ld %ld",&A,&B);
    if(A==0) printf("0");
    else
    {
        convert(A,B,s);
        add_sub(s);
        printf("%s\n",s);
    }
    return 0;
}
