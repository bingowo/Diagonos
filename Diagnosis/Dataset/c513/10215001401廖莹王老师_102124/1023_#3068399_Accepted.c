#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char s[50];
    int d;
}shuru;
int cmp(const void*a,const void*b)
{
    shuru*k1,*k2;
    k1=(shuru*)a;k2=(shuru*)b;
    if(k1->d==k2->d)return strcmp(k1->s,k2->s);
    else return k1->d-k2->d;
}
int main()
{
    shuru p[110];
    int i=0;
    while(scanf("%s",p[i].s)!=EOF)
    {
        int j,k=0,l=0;
        for(j=0;p[i].s[j];j++)
        {
            if(p[i].s[j]>='0' && p[i].s[j]<='9'){k=k*10+(p[i].s[j]-'0');l++;}
        }
        if(l==0)p[i].d=-1;
        else p[i].d=k;
        i++;
    }
    qsort(p,i,sizeof(p[0]),cmp);
    for(int n=0;n<i;n++)printf("%s ",p[n].s);
    return 0;
}
