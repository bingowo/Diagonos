#include<stdio.h>
int max(int a,int b)
{
    return (a>b)? a:b;
}
int plus(int *a,int*b,int* res,int len,int next)
{
    int tmp,i;
    for(i=0;i<len;i++)
    {
        tmp=a[len-i-1]+b[len-i-1]+next;
        res[len-i-1]=tmp%10;
        next=tmp/10;
    }
    return next;
}
int main()
{
    char s[1000],s1[1000];
    scanf("%s %s",s,s1);
    int i,ai[1000],af[1000],bi[1000],bf[1000],resf[1000],tai=0,taf=0,tbi=0,tbf=0,tmp[1000];
    for(i=0;i<1000;i++)
    {
        ai[i]=0;
        bi[i]=0;
        af[i]=0;
        bf[i]=0;
    }
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.') break;
        else tmp[tai++]=s[i]-'0';
    }
    for(int j=0;j<tai;j++) ai[999-j]=tmp[tai-1-j];
    for(;i<strlen(s);i++)
    {
        if(s[i]!='.') af[taf++]=s[i]-'0';
    }
    for(i=0;i<strlen(s1);i++)
    {
        if(s1[i]=='.') break;
        else tmp[tbi++]=s1[i]-'0';
    }
    for(int j=0;j<tbi;j++) bi[999-j]=tmp[tbi-1-j];
    for(;i<strlen(s1);i++)
    {
        if(s1[i]!='.') bf[tbf++]=s1[i]-'0';
    }
    int len=max(tbf,taf),next=0;
    int resi[1000];
    next=plus(af,bf,resf,len,next);
    len=1000;
    next=plus(ai,bi,resi,len,next);
    int test=0;
    for(i=0;i<999;i++)
    {
        if(resi[i]!=0) test=1;
        if(test==1) printf("%d",resi[i]);
    }
    printf("%d",resi[999]);
    printf(".");
    for(i=0;i<max(tbf,taf);i++) printf("%d",resf[i]);
}
