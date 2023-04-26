#include <stdio.h>
#include<string.h>
char m[40];
char table[]="012";
int change(int a,int k)
{
    int i=0;
    while(a!=0)
    {
        m[i]=table[a%3];
        a=a/3;
        i++;
    }
    int j=1;
    while(j<=k-i+1)
    {
        m[i]='0';
        i++;
        j++;
    }
    return i;
}
void reverse(char s[])
{
    int c,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
void add(char s1[],char s2[],int t)
{
    int cpp=0;
    for(int i=t;i>=0;i--)
    {
        if(s1[i]!='.')
        {
            int x=(s1[i]-'0')+(s2[i]-'0')+cpp;
            if(x==3)
            {
                cpp=1;
                s1[i]='0';
            }
            if(x==4)
            {
                cpp=1;
                s1[i]='1';
            }
            if(x==0)
            {
                cpp=0;
                s1[i]='0';
            }
            if(x==1)
            {
                cpp=0;
                s1[i]='1';
            }
            if(x==2)
            {
                cpp=0;
                s1[i]='2';
            }
        }
    }

}
void jian(char s1[],char s2[],int t)
{
    for(int i=0;i<=t;i++)
    {
        int x;
        if(s1[i]!='.')
        {
            x=s1[i]-s2[i];
            if(x==-1)
            {
                x=2;
            }
            s1[i]=(char)(x+48);
        }
    }
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int k=0;
    while(b!=1)
    {
        b=b/3;
        k++;
    }
    int t=change(a,k);
    reverse(m);
    for(int i=t;i>t-k;i--)
    {
        m[i]=m[i-1];
    }
    m[t-k]='.';
    char le[40];
    for(int i=0;i<=t;i++)
    {
        le[i]='1';
    }
    le[t-k]='.';
    add(m,le,t);
    jian(m,le,t);
    printf("%s",m);

}
