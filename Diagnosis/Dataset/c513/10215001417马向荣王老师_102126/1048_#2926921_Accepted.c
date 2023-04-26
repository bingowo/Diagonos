#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define N 100
void read(char *p,int *co)
{
    while(*p!=0)
    {
        int sign=1,coef=0,dim=0;
        if(*p=='-')
        {
            sign=-1;
            p++;
        }
        else if(*p=='+') p++;
        while(isdigit(*p))
        {
            coef=coef*10+*p-'0';
            p++;
        }
        if(*p!='x')
        {
            co[0]=coef*sign;
            return;
        }
        else p++;
        if(coef==0)
        {
            coef=1;
        }
        if(*p=='^')
        {
            p++;
        }
        while(isdigit(*p))
        {
            dim=dim*10+*p-'0';
            p++;
        }
        if(dim==0)
        {
            dim=1;
        }
        co[dim]=coef*sign;
    }
}
void multiply(char *s1,char *s2,int *co)
{
    int co1[N]={0},co2[N]={0};
    read(s1,co1);
    read(s2,co2);
    int i=0,j=0;
    for(i=0;i<N/2;i++)
    {
        for(j=0;j<N/2;j++)
        {
            co[i+j]+=co1[i]*co2[j];
        }
    }
}
int main(void)
{
    char s1[N+1],s2[N+1];
    while((scanf("%s %s",s1,s2))!=EOF)
    {
        int co[N]={0},out[N],n=0,i;//co：系数，out:算后系数
        multiply(s1,s2,co);
        for(i=0;i<N;i++)
        {
            if (co[i]!=0) out[n++]=co[i];
        }
        for(i=n-1;i>=0;i--)
        {
            printf("%d",out[i]);
            if(i>0) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}