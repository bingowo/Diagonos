#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void readpo(char*s,int*co)
{
    while(*s)
    {
        int sign=1,coef=0,dim=0;
        if(*s=='+')s++;
        else if(*s=='-') sign=-1,s++;
        while(isdigit(*s))
        {
            coef=coef*10+*s-'0';
            s++;
        }
        if(coef==0)coef=1;
        if(*s!='x')
        {
            co[0]=coef*sign;return;
        }
        else s++;
        if(*s=='^') s++;
        while(isdigit(*s))
        {
            dim=dim*10+*s-'0';
            s++;
        }
        if(dim==0) dim=1;
        co[dim]=coef*sign;
    }
}

void multiply(char* s1,char* s2,int* result)
{
    int co1[50]={0},co2[50]={0};
    readpo(s1,co1);
    readpo(s2,co2);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
        result[i+j]+=co1[i]*co2[j];

}

int main()
{
    char s1[101],s2[101];

    while (scanf("%s %s",s1,s2)==2)
    {   int result[100]={0};
        multiply(s1,s2,result);

        int flag=0;
        for (int i=99;i>=0;i--)
            {if (result[i])

            {
                flag?printf(" %d",result[i]):printf("%d",result[i]);
                flag=1;
            }
            }
            printf("\n");
    }

    return 0;
}
