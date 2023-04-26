#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isfor(char *a);
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
        p=s;
        q=strchr(s,' ');
        while(q!=NULL)
        {
            *q=0;
            if(!isfor(p))
                res++;
            p=q+1;
            q=strchr(p,' ');
        }
        printf("case #%d:\n",i);
        printf("%d",res);
    }
    return 0;
}
int isfor(char *a)
{
    if(strcmp(a,"the")==0||strcmp(a,"a")==0||strcmp(a,"an")==0||strcmp(a,"of")==0||strcmp(a,"for")==0||strcmp(a,"and")==0)
        return 1;
    else
        return 0;
}
