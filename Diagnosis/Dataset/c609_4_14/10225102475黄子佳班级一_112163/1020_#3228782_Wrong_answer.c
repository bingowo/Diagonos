#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strnumcmp(const void *a,const void *b)
{
    char *s1,*s2,*num1,*num2;
    s1=*((char **)a);
    s2=*((char **)b);
    int j=0,q=0;
    int len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    while(j<len1)
    {
        if(isdigit(s1[j]))break;
        j++;
    }
    if(j!=len1)num1=s1+j;
    while(q<len2)
    {
        if(isdigit(s2[q]))break;
        q++;
    }
    if(q!=len2)num2=s2+q;

    if(j==len1&&q==len2)return strcmp(s1,s2);//都不含数字
    if(j==len1&&q!=len2)return -1;
    if(j!=len1&&q==len2)return 1;//其中一个含数字
    if(j!=len1&&q!=len2)
    {
        if(strlen(num1)==strlen(num2))return strcmp(num1,num2);
        if(strlen(num1)>strlen(num2))return -1;
        if(strlen(num1)<strlen(num2))return 1;
    }//两个都含数字
}

int main()
{
    char **ch;
    char *p;
    ch=(char **)malloc(30*sizeof(char *));
    char s[31];
    int i=0;
    while(scanf("%s",s)<1)
    {
        p=(char *)malloc(30*sizeof(char));
        strcpy(p,s);
        *(ch+i)=p;
        i++;
    }
    qsort(ch,i,sizeof(char *),strnumcmp);
    for(int k=0;k<i;k++)printf("%s ",ch[k]);
    for(int k=0;k<i;k++)
    {
        p=ch[k];
        free(p);
    }
    free(ch);
    return 0;
}