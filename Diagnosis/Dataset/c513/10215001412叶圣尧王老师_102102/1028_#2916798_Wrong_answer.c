#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st 
{
    char b[5];
    int num;
};
int cmpa(const void*a,const void*b)
{
    return (*(struct st*)a).num-(*(struct st*)b).num;
}
int cmpd(const void*a,const void*b)
{
    return (*(struct st*)b).num-(*(struct st*)a).num;
}

int main()
{
    char c;scanf("%c",&c);int i,j,k=0;struct st a[100];
    while(scanf("%s",a[k++].b)!=EOF)
    {a[k-1].num=0;for(j=0;j<strlen(a[k-1].b);j++)a[k-1].num=a[k-1].num*10+a[k-1].b[j]-'0';}
    if(c=='A')qsort(a,k,sizeof(a[0]),cmpa);
    else qsort(a,k,sizeof(a[0]),cmpd);
    printf("%d",a[0].num);
    for(i=1;i<k;i++)if(a[i].num!=a[i-1].num)printf(" %d",a[i].num);
}