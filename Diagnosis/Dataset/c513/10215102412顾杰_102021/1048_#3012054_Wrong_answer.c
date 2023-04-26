#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
void g(char*a,int*x)
{
    char*p=a,*p0=a;
    while(*p)
    {//printf("!%d",atoi(p0));
        while(*p&&*p!='x')p++;
        if(*p=='x')if(*(p+1)=='^')if(!isdigit(*(p-1)))
                                            {if(*(p-1)=='-')x[*(p+2)-'0']=-1;else x[*(p+2)-'0']=1;p0=p+3;}
                                    else{x[*(p+2)-'0']=atoi(p0);p0=p+3;}
                  else if(!isdigit(*(p-1)))
                                {if(*(p-1)=='-')x[1]=-1;else x[1]=1;p0=p+1;}
                        else{x[1]=atoi(p0);p0=p+1;}
        else {x[0]=atoi(p0);break;}
        p++;
    }
}
int main()
{
    char a[101],b[101];
    while(scanf("%s%s",a,b)!=EOF)
    {
        int x[50]={0},y[50]={0},ans[100]={0};
        g(a,x);g(b,y);
        for(int i=0;i<50;i++)for(int j=0;j<50;j++)ans[i+j]+=x[i]*y[j];
        for(int i=99;i>=0;i--)if(ans[i]!=0)printf("%d ",ans[i]);
        printf("\n");

    }
}
