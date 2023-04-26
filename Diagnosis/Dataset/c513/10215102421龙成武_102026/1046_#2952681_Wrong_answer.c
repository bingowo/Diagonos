#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isfor(char *a);
int strcmp1(char *a,char *b);
int main()
{
    int T,i,res;
    char s[105],*p,*q;
    scanf("%d",&T);getchar();
    s[0]=' ';
    for(i=0;i<T;i++)
    {
        res=0;
        gets(s+1);
        s[strlen(s)+1]=0;
        s[strlen(s)]=' ';
        p=s;
        q=strchr(s+1,' ');
        while(q!=NULL)
        {
            *q=0;
            if(!isfor(p))
                res++;
            p=q+1;
            q=strchr(p,' ');
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
int strcmp1(char *a,char *b)
{
    int flag=0;
    for(int i=0;i<strlen(a);i++)
        if(a[i]!=b[i])
            flag=1;
    return flag;
}
int isfor(char *a)
{
    if(strcmp1(a,"the")==0||strcmp1(a,"a")==0||strcmp1(a,"an")==0||strcmp1(a,"of")==0||strcmp1(a,"for")==0||strcmp1(a,"and")==0)
        return 1;
    else
        return 0;
}
