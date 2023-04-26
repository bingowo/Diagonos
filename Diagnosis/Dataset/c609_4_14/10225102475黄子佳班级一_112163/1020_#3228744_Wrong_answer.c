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
    while(isdigit(s1[j])==0)j++;
    if(j!=strlen(s1))num1=s1+j;
    while(isdigit(s2[q])==0)q++;
    if(q!=strlen(s2))num2=s2+q;

    if(q==0&&j==0)return strcmp(s1,s2);//都不含数字
    if((j==0&&q!=0)||(j!=0&&q==0))return q-j;//其中一个含数字
    if(j!=0&&q!=0)
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
    p=(char *)malloc(8*sizeof(char));
    int i=0;
    while(scanf("%s",p)<1)
    {
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
