#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100000
typedef struct{char al[N];int num;}alph;


int number(char s[])
{
    int p[128],j=0,k=1,i;
    for(i=1;i<strlen(s);i++)p[s[i]]=-1;
    p[s[0]]=1;
    while(j<strlen(s))
    {
        if(p[s[j]]==-1)p[s[j]]=1,k++,j++;
        else j++;
    }
    return k;
}

int compare(const void*a,const void*b)
{
    alph c=*(alph*)a;
    alph d=*(alph*)b;
    if(c.num!=d.num)return d.num-c.num;
    else if(strcmp(c.al,d.al)>0)return 1;
    else if(strcmp(c.al,d.al)<=0)return -1;
}

int main()
{
    int i,n,cas,j,k;
    alph *s;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cas);
        s=(alph*)malloc(cas*sizeof(alph));
        for(j=0;j<cas;j++)scanf("%s",s[j].al);
        for(j=0;j<cas;j++)s[j].num=number(s[j].al);
        qsort(s,cas,sizeof(s[0].num),compare);
        printf("case #%d:\n",i);
        for(k=0;k<cas;k++)printf("%s\n",s[k].al);
    }
    free(s);
    return 0;
}
