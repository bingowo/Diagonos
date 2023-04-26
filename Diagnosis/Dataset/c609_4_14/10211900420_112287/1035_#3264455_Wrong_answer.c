#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add(char x[101],char a[101],int y,char z)
{
    int len=strlen(x);
    for(int i=0;i<y;i++)
    {
        a[i]=x[i];
    }
    a[y]=z;
    for(y=y;y<len;y++)
    {
        a[y+1]=x[y];
    }
    a[len+1]='\0';
}
void sub(char x[101],int y)
{
    int len=strlen(x);
    for(y=y+1;y<len;y++)
    {
        x[y-1]=x[y];
    }
    x[len-1]='\0';
}
int num(char x[101])
{
    int flag=0,len1=strlen(x),len2=0,um=0;
    while(len1!=len2)
    {
        flag=0;
        int del[101]={0};
        len1=strlen(x);
        for(int i=1;i<len1;i++)
        {
            if(x[i]==x[i-1] && x[i]==x[i+1])
            {
                del[flag++]=i-1;
                um++;
            }
            else if(x[i]==x[i-1] && x[i]!=x[i+1])
            {
                del[flag++]=i-1;
                del[flag++]=i;
                um=um+2;
            }
        }
        for(int i=flag-1;i>=0;i--)
        {
            sub(x,del[i]);
        }
        len2=strlen(x);
    }
    return um;
}
int main()
{
    int T,max,um1,um2,um3;
    char a[101],b[101],c[101],d[101];
    scanf("%d",&T);
    for(int n=0;n<T;n++)
    {
        max=0;
        scanf("%s",a);
        for(int i=0;i<strlen(a);i++)
        {
            add(a,b,i,'A');
            add(a,c,i,'B');
            add(a,d,i,'C');
            um1=num(b);
            if(max<um1) max=um1;
            um2=num(c);
            if(max<um2) max=um2;
            um3=num(d);
            if(max<um3) max=um3;
        }
        printf("case #%d:\n%d",n,max);
    }
    return 0;
}
