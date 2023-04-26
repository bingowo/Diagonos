#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define C 5000
void slo(int n,int a[],int f[])
{   int j,t;
    for(int i=C-1;i>=0;i--)
    {
        t=n*a[i];
        j=0;
           f[i+j]+=t;
        while(f[i+j]>=10)
        {   f[i+j-1]+=f[i+j]/10;
            f[i+j]=f[i+j]%10;
            j--;
        }
    }
}
void add(int a[],int b[])
{   int i,t,carry=0;
    for(i=C-1;i>=0;i--)
    {
        t=a[i]+b[i]+carry;
        a[i]=t%10;
        carry=t/10;
    }
}
void time(int a[],int b[])
{   int i,t;
    for(i=C-1;i>=0;i--)
    {
        t=a[i]-b[i];
        if(t<0)
        {
            a[i-1]--;
            a[i]=t+10;
        }
        else
            a[i]=t;
    }
}
int check(int a[],int b[])
{   int i=0;
    while(a[i]==b[i])
        i++;
    if(a[i]>b[i])
        return 1;
    else
        return 0;
}
int main()
{
    char s[20];
    int fan,fbn,fa=1,fb=1,na=0,nb=0,a[C]= {0},b[C]= {0};
    scanf("%s",s);
    int i=0;
    if(s[i]=='+')i++;
    else if(s[i]=='-') fa=-1,i++;
    while(isdigit(s[i]))
    {
        na=na*10+s[i]-'0';
        i++;
    }
    if(s[i]=='i')
    {
        nb=na;
        na=0;
    }
    else{
    if(na==0)na=1;
    if(s[i]=='+')i++;
    else if(s[i]=='-') fb=-1,i++;
    while(isdigit(s[i]))
    {
        nb=nb*10+s[i]-'0';
        i++;
    }
    if(nb==0&&s[i]=='i')nb=1;
    else if(nb==0&&s[i]!='i')nb=0;
    }
    int id,n,t;
    scanf("%d",&n);
    id=0;t=na;
    while(t>0)
    {
        a[C-1-id++]=t%10;
        t/=10;
    }
    id=0;t=nb;
    while(t>0)
    {
        b[C-1-id++]=t%10;
        t/=10;
    }
    fan=fa,fbn=fb;
     for(int i=0;i<n-1;i++)
    {
        int c[C]={0},d[C]={0},e[C]={0},f[C]={0};
        int fc,fd,fe,ff;
        fc=fa*fan;
        fd=-fbn*fb;
        fe=fan*fb;
        ff=fbn*fa;
        slo(na,a,c);
        slo(nb,b,d);
        slo(nb,a,e);
        slo(na,b,f);
        if(fc*fd>0)
        {
            add(c,d);
            memcpy(a,c,4*C);
            fan=fc;
        }
        else
        {
                 if(check(c,d)==1)
                 {
                  time(c,d);
                   memcpy(a,c,4*C);
                  fan=fc;
                 }
                 else
                 {
                     time(d,c);
                      memcpy(a,d,4*C);
                  fan=fd;
                 }
        }
        if(ff*fe>0)
        {
            add(e,f);
            memcpy(b,e,4*C);
            fbn=fe;
        }
        else
        {
            if(check(e,f)==1)
            {
                time(e,f);
                memcpy(b,e,4*C);
                fbn=fe;
            }
            else
            {
                time(f,e);
                memcpy(b,f,4*C);
                fbn=ff;
            }
        }
    }
    int f=0;
    for(int i=0;i<C;i++)
    {
        if(a[i]==0&&f==0)
            continue;
        else
            f++;
        if(f==1&&fan==-1)
            printf("-");
        printf("%d",a[i]);
    }
    f=0;
    for(int i=0;i<C;i++)
    {
        if(b[i]==0&&f==0)
            continue;
        else
            f++;
        if(f==1&&fbn==-1)
            printf("-");
        else if(f==1&&fbn==1)
            printf("+");
        if(f==1&&i==C-1&&b[i]==1)
            ;
        else
         printf("%d",b[i]);
        if(i==C-1)
        printf("i");
    }

    return 0;
}
