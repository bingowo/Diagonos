#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int number(char *str)
{
    int i,n=0,l,f=0;
    for(i=0;str[i];i++)
    {
        if(isdigit(str[i])){n=n*10+(str[i]-'0');f=1;}
    }
    if(f==0)n=-1;
    return n;
}
strnumcmp(const void *a,const void*b)
{
    char *str1,*str2;
    int s1,s2;
    str1=(char*)a;
    str2=(char*)b;
    s1=number(str1);
    s2=number(str2);
    if(s1==s2) return strcmp(str1,str2);
    else {if(s1>s2) return s1-s2;else return -1;}

}
int main()
{
    char str[110][40];
    int n=0,i=0;
    while(scanf("%s",str[n])!=EOF)n++;
    qsort(str,n,sizeof(str[0]),strnumcmp);
    for(i=0;i<n;i++)
    {
        printf("%s ",str[i]);
    }
    printf("\n");
    return 0;
}
