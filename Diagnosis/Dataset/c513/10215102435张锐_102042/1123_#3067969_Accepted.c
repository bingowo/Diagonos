#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[50];
    int n;
}DNA;
int cmp1(const void *a,const void *b)
{
    DNA* s1=(DNA*)a,*s2=(DNA*)b;
    return strcmp(s1->s,s2->s);
}
int cmp(const void *a,const void *b)
{
    DNA* s1=(DNA*)a,*s2=(DNA*)b;
    if(s1->n>s2->n) return 1;
    else if(s1->n<s2->n) return -1;
    else 
    {
        return -strcmp(s1->s,s2->s);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    DNA* p=(DNA*)malloc(sizeof(DNA)*t);
    int num=0;
    for(int f=0;f<t;f++)
    {
        scanf("%s",p[num++].s);p[f].n=1;
    }
    qsort(p,num,sizeof(p[0]),cmp1);
    int all=1;int n=0;
    for(int f=0;f<num;f++)
    {
        if(f<num-1&&strcmp(p[f].s,p[f+1].s)==0) n--;
        else if(f<num-1&&strcmp(p[f].s,p[f+1].s)!=0) {p[f].n=n;n=0;all++;}
        if(f==num-1) p[f].n=n;
    }
    qsort(p,num,sizeof(p[0]),cmp);
    for(int i=all-1;i>=0;i--)
    {
        printf("%s\n",p[i].s);
    }
    free(p);
    return 0;
}