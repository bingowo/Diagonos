#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pick(char *s1,char s2[][17],int* b,int num,int lenth)
{
    if(num==0)
    {
        b[0]++;
        return 0;
    }
    if(lenth>=num)
    {
        if(lenth>=(num+1))
        {
            b[0]++;
            pick(s1,s2,b,num,lenth-1);
        }
        s2[b[0]][num-1]=s1[lenth-1];
        pick(s1,s2,b,num-1,lenth-1);
    }
}


int cmp(const void*a,const void*b)
{
    char* p1;
    char* p2;
    p1=(char*)a;
    p2=(char*)b;
    if(*p1<91&&*p2<91)
        return (*p1-*p2);
    if(*p1>91&&*p2>91)
        return (*p1-*p2);
    if(*p1>91&&*p2<91)
        return 1;
    return -1;
}

int cmp2(const void*a,const void*b)
{
    char * ap=*(char**)a;
    char * bp=*(char**)b;
    if(strcmp(ap,bp)>0)
        return 1;
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[17]={0};
        scanf("%s",s);
        int a[127]={0};
        int j,p=0,l,m=0;
        char s1[17]={0};
        int b[1]={0};
        char s2[1000][17]={0};
        for(j=0;s[j];j++)
        {
            if(a[s[j]]==0)
            {
                a[s[j]]=1;
                s1[p++]=s[j];
            }
        }
        qsort(s1,p,sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(j=1;j<=p;j++)
        {
            pick(s1,s2,b,j,p);
        }
        qsort(s2,m,sizeof(char),cmp2);
        for(j=0;j<b[0];j++)
            printf("%s\n",s2[j]);
    }
}