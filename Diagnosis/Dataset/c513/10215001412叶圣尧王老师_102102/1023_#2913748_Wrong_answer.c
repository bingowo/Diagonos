#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
    char str[31];
    int num;
    int sign;
};

int cmp(const void*a,const void*b)
{
    return strcmp((*(struct st*)a).str,(*(struct st*)b).str);
}

int cmp1(const void*a,const void*b)
{
    return (*(struct st*)a).num-(*(struct st*)b).num;
}

int main()
{
    int n=0,i,j;
    struct st s[100],s1[100],s2[100];
    for(i=0;scanf("%s",s[i].str)!=EOF;i++)
    {
        s[i].num=0;s[i].sign=-1;
        for(j=0;j<strlen(s[i].str);j++)
        {
            if(s[i].str[j]<='9'&&s[i].str[j]>='0'){s[i].num=s[i].num*10+s[i].str[j]-'0';s[i].sign=1;}
        }
    }
    int k1=0,k2=0;
    for(j=0;j<i;j++)
        if(s[j].sign==1)s1[k1++]=s[j];
        else s2[k2++]=s[j];
    qsort(s2,k2,sizeof(s[0]),cmp);
    qsort(s1,k1,sizeof(s[0]),cmp1);
    for(j=0;j<k2;j++)printf("%s ",s2[j].str);
    for(j=0;j<k1;j++)printf("%s ",s1[j].str);
    
}