#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void read(char *p,int *co)
{
    while(*p)
    {
        int c=0,d=0;
        int sign=1;
        if(*p=='+') p++;
        else if(*p=='-')
        {
            sign=-1;
            p++;
        }
        while(isdigit(*p))
        {
            c=c*10+*p-'0';
            p++;
        }
        if(*p!='x')
        {
            co[0]=c*sign;return;
        }
        else p++;
        if(c==0) c=1;
        if(*p=='^') p++;
        while(isdigit(*p))
        {
            d=d*10+*p-'0';;
            p++;
        }
        if(d==0) d=1;
        co[d]=c*sign;
    }
}
void mul(char *s1,char *s2,int* co)
{
    int co1[101]={0},co2[101]={0},i,j;
    read(s1,co1);read(s2,co2);
    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
        {
            co[i+j]+=co1[i]*co2[j];
        }
    }
}
int main()
{
    char s1[101];
    char s2[101];
    while(scanf("%s %s",s1,s2)==2)
    {
        int co[101]={0},out[101],n=0,i;
        mul(s1,s2,co);
        for(i=0;i<100;i++)
        {
            if(co[i]) out[n++]=co[i];
        }
        for(i=n-1;i>=0;i--)
        {
            printf("%d",out[i]);
            if(i>0)
            {
                printf(" ");
            }
            else printf("\n");
        }
    }
}
