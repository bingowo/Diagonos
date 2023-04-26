#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>



void readpoly(char *s,int *co)
{
    while(*s)
    {
        int sgn=1,cof=0,dim=0;
        if(*s=='+') s++;
        else if(*s=='-') {sgn=-1;s++;}
        while(isdigit(*s)) {cof=cof*10+(*s)-'0';s++;}
        if(cof==0) cof=1;
        if(*s!='x') {co[0]=cof*sgn;return;}
        else s++;
        if(*s=='^') s++;
        while(isdigit(*s)) {dim=dim*10+(*s)-'0'; s++;}
        if(dim==0) dim=1;
        co[dim]=cof*sgn;
    }
}

void mult(char *s1,char *s2,int *res)
{
    int co1[50]={0},co2[50]={0};
    readpoly(s1,co1);
    readpoly(s2,co2);
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++)
            res[i+j]+=co1[i]*co2[j];
        }
}

int main()
{
    char s1[101],s2[101];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int flag=0;
        for(int i=99;i>=0;i--)
        {
            int res[100]={0};
            mult(s1,s2,res);
            if(res[i])
            {
                flag?printf(" %d",res[i]):printf("%d",res[i]);
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}