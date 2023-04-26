#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct DNA
{
    char str[21];
    int ape;
    int len;
}dna;
int cmp1(const void* q1,const void* q2)
{
    dna* a=(dna* )q1;
    dna* b=(dna* )q2;
    return (strcmp(a->str,b->str));
}
int cmp2(const void* q1,const void* q2)
{
    dna* a=(dna* )q1;
    dna* b=(dna* )q2;
    if(a->ape!=b->ape)
        return (a->ape-b->ape);
    else 
        return (strcmp(a->str,b->str));
}
int main()
{
    dna s[200000];
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i].str);
        s[i].ape=1;
        s[i].len=strlen(s[i].str);
    }
    qsort(s,n,sizeof(s[0]),cmp1);
   
    for(int j=0;j<n;j++)
    {
        if(strcmp(s[j].str,s[j+1].str)==0) 
        {
            s[j+1].ape=s[j].ape+s[j+1].ape;
            s[j].ape=0;               
        }
    }
    qsort(s,n,sizeof(s[0]),cmp2);
    for(int k=0;k<n;k++)
    {
        if(s[k].ape!=0)
            printf("%s\n",s[k].str);
    }
    return 0;
}