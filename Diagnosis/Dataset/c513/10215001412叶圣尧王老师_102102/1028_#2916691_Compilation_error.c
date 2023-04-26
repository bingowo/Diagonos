#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpa(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int cmpd(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char c;scanf("%c",&c);int i,k=0,a[100];
    while(scanf("%d",&a[k++])!=EOF);
    if(c=='A')qsort(a,k,sizeof(a[0]),cmpa);
    else qsort(a,k,sizeof(a[0]),cmpb);
    printf("%d",a[0]);
    for(i=1;i<k;i++)if(a[i]!=a[i-1])printf(" %d",a[i]);
}