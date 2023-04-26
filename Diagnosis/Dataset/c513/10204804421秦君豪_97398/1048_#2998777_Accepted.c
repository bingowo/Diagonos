#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int n;//
}data;

void solve(char* s,int* n)
{
    while(*s)
    {
        int sign=1,coef=0,dim=0;
        if(*s=='+') s++;
        else if(*s=='-')
        {
            sign=-1;
            s++;
        }
        while(isdigit(*s)) {coef=coef*10+*s-'0';s++;}
        if(coef==0) coef=1;
        if(*s!='x')
        {
            n[0]=coef*sign;
            return;
        }
        else
            s++;
        if (*s=='^') s++;
        while (isdigit(*s)) {dim=dim*10+*s-'0';s++;}
        if (dim==0) dim=1;
        n[dim]+=coef*sign;
    }
}

int main()
{
    char s1[101],s2[101];
    int n1[50]={0};
    int n2[50]={0};

    int result[100];
    while (scanf("%s%s",s1,s2)!=EOF)
    {
        memset(result,0,sizeof(result));
        memset(n1,0,sizeof(n1));
        memset(n2,0,sizeof(n2));
        solve(s1,n1);
        solve(s2,n2);
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<50;j++)
            {
                result[i+j]+=n1[i]*n2[j];
            }
        }
        int flag=0;
        for(int i=99;i>=0;i--)
        {
            if(result[i])
            {
                flag?printf(" %d",result[i]):printf("%d",result[i]);
                flag=1;
            }

        }
        printf("\n");
    }

    return 0;
}
