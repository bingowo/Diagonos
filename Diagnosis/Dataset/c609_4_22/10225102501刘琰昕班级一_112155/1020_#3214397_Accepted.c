#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num(const char *str)
{
    int n=-1;char *p=str;
    while(*p)
    {
        if(*p>='0'&&*p<='9')
        {
            if(n==-1)n=0;
            n=10*n+*p-'0';
        }
        p++;
    }
    return n;
}

int cmp(const char *a,const char *b)
{
    char *str1=a,*str2=b;
    int number1,number2;
    number1=num(str1);
    number2=num(str2);
    if(number1!=number2)
        return number1>number2?1:-1;
    else
        return strcmp(str1,str2);
}

int main()
{
    char str[101][31]={0};int n=0;
    while(scanf("%s",str[n])!=EOF)n++;
    qsort(str,n,sizeof(str[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%s ",str[i]);
    return 0;
}
