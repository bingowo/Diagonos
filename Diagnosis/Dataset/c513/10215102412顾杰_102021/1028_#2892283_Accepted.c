#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int cmpa(const void*a,const void*b)
{
    return *(int*)a>*(int*)b?1:-1;
}
int cmpb(const void*a,const void*b)
{
    return *(int*)a>*(int*)b?-1:1;
}
int main() {
    char c;
    int a[1000],i=-1,j,n,f=1;
    scanf("%c",&c);
    while(scanf("%d",&n)!=-1)
    {
        i++;
        for(j=0;j<i;j++)if(a[j]==n){i--;f=0;break;}
        if(f)a[i]=n;
        else f=1;
    }
    if(c=='A')qsort(a,i+1,sizeof(a[0]),cmpa);
    else qsort(a,i+1,sizeof(a[0]),cmpb);
    for(j=0;j<i;j++)printf("%d ",a[j]);
    printf("%d",a[j]);
    return 0;
}
