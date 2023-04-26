#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convert(int a[])
{
    int sum=0;
    for(int i=0;i<strlen(a);i++)
    {
        sum=sum*10+a[i];
    }
    return sum;
}

int strnumcmp(const void *a,const void *b)
{
    char *s1,*s2;
    int num1[9],num2[9];
    for(int i=0;i<9;i++)
    {
        num1[i]=-1;
        num2[i]=-1;
    }
    s1=*((char **)a);
    s2=*((char **)b);

    int j=0,q=0;
    int len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    int i=0;
    while(j<len1)
    {
        if(isdigit(s1[j]))
        {
            while(isdigit(s1[j]))num1[i++]=s1[j++];
            break;
        }
        j++;
    }
    i=0;
    while(q<len2)
    {
        if(isdigit(s2[q]))
        {
            while(isdigit(s2[q]))num2[i++]=s2[q++];
            break;
        }
        q++;
    }
    int sum1=convert(num1);
    int sum2=convert(num2);

    if(num1[0]==-1&&num2[0]==-1)return strcmp(s1,s2);//都不含数字
    if(num1[0]==-1&&num2[0]!=-1)return -1;
    if(num1[0]!=-1&&num2[0]==-1)return 1;//其中一个含数字
    if(num1[0]!=-1&&num2[0]!=-1)return sum1-sum2;//两个都含数字
}

int main()
{
    char **ch;
    char *p;
    char s[31];
    ch=(char **)malloc(100*sizeof(char *));
    int i=0;
    while(scanf("%s",s)!=EOF)
    {
        p=(char *)malloc(strlen(s)+1);
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
