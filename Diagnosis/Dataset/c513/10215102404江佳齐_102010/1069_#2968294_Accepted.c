#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int count=0;
char t[30];
int f(char s[])
{
    count++;
    int i=strlen(s)-1,j=0;
    for(i=strlen(s)-1,j=0;i>=0;i--,j++) t[j]=s[i];
    t[j]='\0';
    int m=atoi(s);int n=atoi(t);
    int v=m+n;int temp=0;
    char x[30]={0};
    sprintf(x,"%d",v);
    for(int i=0,j=strlen(x)-1;i<j;i++,j--)
    {
        if(x[i]!=x[j])
        {
            temp=0;break;
        }
        else temp=1;
    }
    if(temp==0) v=f(x);
    return v;
}
int main()
{
    char s[30];
    scanf("%s",s);
    int result=f(s);
    printf("%d %d",count,result);
    return 0;
}
