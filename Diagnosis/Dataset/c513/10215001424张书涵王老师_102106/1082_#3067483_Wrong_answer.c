#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(char* s)
{
    int i,j,l;
    char c;
    l=strlen(s);
    for(i=0,j=l-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    char s1[1000]={0},s2[1000]={0},s[1000]={0};
    int c[1000]={0},c1[1000]={0};
    int N,lenth1,lenth2,decimals_num1=0,decimals_num2=0,k1=0,k2=0;
    scanf("%s %s %d",s1,s2,&N);
    lenth1=strlen(s1);lenth2=strlen(s2);
    int i;
    if(s1[0]=='.')
    {
        for(i=lenth1-1;i>=0;i--)
            s1[i+1]=s1[i];
        s1[0]='0';
    }
    if(s2[0]=='.')
    {
        for(i=lenth2-1;i>=0;i--)
            s2[i+1]=s2[i];
        s2[0]='0';
    }
    for(i=0;s1[i];i++)
    {
        if(s1[i]=='.')
        {
            k1=1;
            i++;
            for(;s1[i];i++)
                decimals_num1++;
            break;
        }
    }
    for(i=0;s2[i];i++)
    {
        k2=1;
        if(s2[i]=='.')
        {
            i++;
            for(;s2[i];i++)
                decimals_num2++;
            break;
        }
    }
    lenth1=strlen(s1);lenth2=strlen(s2);
    if(decimals_num1>decimals_num2)
    {
        if(k2==0)
        {
            s2[lenth2]='.';
            for(i=lenth2+1;i<(lenth2+decimals_num1-decimals_num2+1);i++)
                s2[i]='0';
        }
        else
        {
            for(i=lenth2;i<(lenth2+decimals_num1-decimals_num2);i++)
                s2[i]='0';
        }
    }
    if(decimals_num1<decimals_num2)
    {
        if(k1==0)
        {
            s1[lenth1]='.';
            for(i=lenth1+1;i<(lenth1+decimals_num2-decimals_num1+1);i++)
                s1[i]='0';
        }
        else
        {
            for(i=lenth1;i<(lenth1+decimals_num2-decimals_num1);i++)
                s1[i]='0';
        }
    }
    reverse(s1);reverse(s2);
    int p=0;
    for(i=0;s1[i]||s2[i];i++)
    {
        if(s1[i]=='.'&&s2[i]=='.')
            c[p++]=-1;
        else
        {
            if(s1[i]==0)
                c[p++]=s2[i]-'0';
            else
            {
                if(s2[i]==0)
                    c[p++]=s1[i]-'0';
                else
                    c[p++]=s1[i]-'0'+s2[i]-'0';
            }
        }
    }
    for(i=0;i<p;i++)
    {
        if(c[i]>=10)
        {
            if(c[i+1]==-1)
            {
                c[i+2]=c[i]/10+c[i+2];
                c[i]=c[i]%10;
                i++;
            }
            else
            {
                if(i==p-1)
                    p++;
                c[i+1]=c[i]/10+c[i+1];
                c[i]=c[i]%10;
            }
        }
    }
    for(i=0;i<p;i++)
    {
        if(c[i]==-1)
            s[i]='.';
        else
            s[i]=c[i]+'0';
    }
    reverse(s);
    int q;
    for(i=0;s[i];i++)
    {
        if(s[i]=='.')
        {
            c1[i]=-1;
            q=i+1;
            for(i=q;i<(q+N);i++)
            {
                if(s[i]==0)
                    c1[i]=0;
                else
                    c1[i]=s[i]-'0';
            }
            if(s[i]>'4')
                c1[i-1]++;
            break;
        }
        else
        {
            q=i+1;
            c1[i]=s[i]-'0';
        }
    }
    if(i<(q+N))
    {
        c1[i]=-1;
        q=i+1;
        for(i=q;i<(q+N);i++)
            c1[i]=0;
    }
    int j1,j2,c2;
    for(j1=0,j2=i-1;j1<j2;j1++,j2--)
    {
        c2=c1[j1];
        c1[j1]=c1[j2];
        c1[j2]=c2;
    }
    for(j1=0;j1<i;j1++)
    {
        if(c1[j1]>=10)
        {
            if(j1==i-1)
                i++;
            if(c1[j1+1]==-1)
            {
                c1[j1+2]=c1[j1+2]+c1[j1]/10;
                c1[j1]=c1[j1]%10;
                j1++;
            }
            else
            {
                c1[j1+1]=c1[j1+1]+c1[j1]/10;
                c1[j1]=c1[j1]%10;
            }
        }
    }
    for(j1=0,j2=i-1;j1<j2;j1++,j2--)
    {
        c2=c1[j1];
        c1[j1]=c1[j2];
        c1[j2]=c2;
    }
    for(j1=0;j1<i;j1++)
    {
        if(c1[j1]==-1)
            printf(".");
        else
            printf("%d",c1[j1]);
    }
}