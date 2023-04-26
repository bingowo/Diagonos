#include <stdio.h>
#include <stdlib.h>
void qingchu(char s[50],char t[20])
{
    int i,j;
    for(i=0;t[i];i++)
    {
        j=strchr(s,t[i])-(int)&s[0];

        s[j]='1';
    }
}
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
void jisuan(int h)
{
    char s[50]={0};
    int k[50]={0};
    int i=0,j=0;
    scanf("%s",s);
    for(i=0;s[i];i++)
    {
        if(s[i]=='Z'){qingchu(s,"ZERO");k[j]=0;j++;}
        if(s[i]=='W'){qingchu(s,"TWO");k[j]=2;j++;}
        if(s[i]=='U'){qingchu(s,"FOUR");k[j]=4;j++;}
        if(s[i]=='X'){qingchu(s,"SIX");k[j]=6;j++;}
        if(s[i]=='G'){qingchu(s,"EIGHT");k[j]=8;j++;}
    }
     for(i=0;s[i];i++)
    {
        if(s[i]=='O'){qingchu(s,"ONE");k[j]=1;j++;}
        if(s[i]=='R'){qingchu(s,"THREE");k[j]=3;j++;}
        if(s[i]=='F'){qingchu(s,"FIVE");k[j]=5;j++;}
        if(s[i]=='S'){qingchu(s,"SEVEN");k[j]=7;j++;}
    }
    for(i=0;s[i];i++)
    {
        if(s[i]=='N'){qingchu(s,"NINE");k[j]=9;j++;}
    }
    qsort(k,j,sizeof(k[0]),cmp);
    printf("case #%d:\n",h);for(i=0;i<j;i++)printf("%d",k[i]);
    printf("\n");
}
int main()
{
    int n,h;scanf("%d",&n);for(h=0;h<n;h++)jisuan(h);
    return 0;
}
