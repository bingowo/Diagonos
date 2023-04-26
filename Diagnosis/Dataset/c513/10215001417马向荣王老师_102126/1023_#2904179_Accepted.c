#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int number(char *a)
{
    int len=strlen(a);
    int i,flag=0,sum=0;
    for(i=0;i<len;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            sum=sum*10+a[i]-48;
            flag=1;
        }
    }
    if(flag==0) sum=-1;
    return sum;
}
int strnumcmp(const void *a,const void *b)
{
    int s1,s2;
    char *c1,*c2;
    c1=(char*)a;
    c2=(char*)b;
    s1=number(c1);
    s2=number(c2);
    if(s1==s2) return strcmp(c1,c2);
    else
    {
        if(s1>s2) return 1;
        else return -1;
    }
}
int main()
{
    char str[200][40];
    int line=0;
    while(scanf("%s",str[line])!=EOF) line++;
    qsort(str,line,sizeof(str[0]),strnumcmp);
    int j=0;
    for(j=0;j<line-1;j++)
    {
        printf("%s ",str[j]);
    }
    printf("%s\n",str[j]);
    return 0;
}