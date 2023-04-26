#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct duo
{
    int a;
    int b;
};
int fuzhi(char shi1[101],struct duo d1[50])
{
    int i,j,flag=0;
    for(i=0,j=0;i<strlen(shi1);i++,j++)
    {
        if(shi1[i]=='-')
            {
                flag=1;
                i++;
            }
        else if(shi1[i]=='+')
        {
            flag=0;
            i++;
        }
        if(isdigit(shi1[i]))
        {
            d1[j].a=d1[j].a*10+shi1[i]-'0';
            while(i+1<strlen(shi1)&&isdigit(shi1[i+1]))
            {
                i++;
                d1[j].a=d1[j].a*10+shi1[i]-'0';
            }
            if(i+1<strlen(shi1))
                i++;
        }
        if(shi1[i]=='x')
        {
            if(shi1[i+1]=='^')
            {
                i+=2;
                d1[j].b=d1[j].b*10+shi1[i]-'0';
                if(i+1<strlen(shi1)&&isdigit(shi1[i+1]))
                {
                    i++;
                    d1[j].b=d1[j].b*10+shi1[i]-'0';
                }
            }
            else
            {
                d1[j].b=1;
            }
            if(d1[j].a==0)
                d1[j].a=1;
        }
        else
        {
            d1[j].b=0;
        }
        if(flag)
        {
            d1[j].a*=-1;
        }
    }

    return j;
}
int main()
{
    int n1,n2;
    char shi1[101],shi2[101];
    while(scanf("%s%s",shi1,shi2)!=EOF)
    {
        struct duo d1[50]={{0,0}},d2[50]={{0,0}};
        int d3[100]={0};
        int i,j;
        n1=fuzhi(shi1,d1);
        n2=fuzhi(shi2,d2);
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++)
            {
                d3[d1[i].b+d2[j].b]+=d1[i].a*d2[j].a;
            }
        }
        for(i=99;i>=0;i--)
        {
            if(d3[i]!=0)
            {
                printf("%d ",d3[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
/*
x+1 x-1
x^2-3x+1 x^3
x+2 2
*/
