#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int su(int a[],int len)
{
    int flag=0,b[101];
    for(int i=0;i<len;i++)
    {
        if((a[i]+flag*10)%2==0)
        {
            a[i]=(a[i]+flag*10)/2;
            flag=0;
        }
        else if((a[i]+flag*10)%2!=0 && (a[i]+flag*10)==1)
        {
            a[i]=0;
            flag=1;
        }
        else if((a[i]+flag*10)%2!=0 && (a[i]+flag*10)!=1)
        {
            a[i]=(a[i]+flag*10)/2;
            flag=1;
        }
    }
    return flag;
}

char num[10]={'0','1','2','3','4','5','6','7','8','9'};
int nu(char a[],int len,int b[])
{
    int sign=0;
    if(a[0]=='-')
    {
        sign=-1;
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(a[i]==num[j])
                {
                    b[i-1]=j;
                    break;
                }
            }
        }
    }
    else
    {
        sign=1;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(a[i]==num[j])
                {
                    b[i]=j;
                    break;
                }
            }
        }
    }
    return sign;
}
int fla(int a[],int len)
{
    int flag;
    for(int i=0;i<len;i++)
    {
        if(a[i]!=0)
        {
            flag=1;
            return 1;
        }
    }
    return 0;
}
void add(int a[],int len)
{
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]!=9)
        {
            a[i]++;
            break;
        }
        else
        {
            a[i]=0;
        }
    }
}
int main()
{
    int yu,b[501],c[501],n=0;
    char a[101]={0};
    scanf("%s",&a);
    int len=strlen(a);
    int sign=nu(a,len,b);
    int flag=fla(b,len);
    if(sign==-1) len--;
    while(flag==1)
    {
        if(sign==-1)
        {
            yu=su(b,len);
            if(yu==1)
            {
                add(b,len);
                c[n]=1;
            }
            else
                c[n]=0;
            sign=1;
        }
        else
        {
            yu=su(b,len);
            if(yu==1)
            {
                c[n]=1;
            }
            else
                c[n]=0;
            sign=-1;
        }
        flag=fla(b,len);
        n++;
    }
    for(int i=n-1;i>=0;i--)
    {
        printf("%d",c[i]);
    }
    if(b[0]==0 && len==1)
        printf("0");
    return 0;
}
/*
#include<iostream>
#include<string>
struct BIGINT
{
    int cnt;
    int v[501];
};
int div(BIGINT *n)
{
    int i,carry;
    if(n->v[n->cnt-1]<2)
        {
            n->cnt--;
            carry=1;
        }
    else carry=0;
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
    return carry;
}
void add(BIGINT *n)
{
    for(int i=0;i<=n->cnt-1;i++)
    {
        if(n->v[i]!=9)
        {
            n->v[i]++;
            break;
        }
        else
        {
            n->v[i]=0;
        }
    }
}
int fla(BIGINT n)
{
    for(int i=n.cnt-1;i>=0;i--)
    {
        if(n.v[i]!=0)
        {
            return 1;
        }
    }
    return 0;
}
using namespace std;
int main()
{
    string s;
    cin>>s;
    int g=0,carry,sign=1,c[501],len=s.size();
    BIGINT n={0,{0}};
    for(int i=len-1;i>=1;i--)
    {
        n.v[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-')
    {
        sign=-1;
    }
    else
    {
        n.v[n.cnt++]=s[0]-'0';
    }
    int flag=fla(n);
    while(flag==1)
    {
        carry=div(&n);
        if(carry==1)
            {
                c[g]=1;
                if(sign==-1) add(&n);
            }
        else c[g]=0;
        sign=(-1)*sign;
        flag=fla(n);
        g++;
    }
    for(int i=g-1;i>=0;i--)
    {
        cout<<c[i];
    }
    return 0;
}
*/