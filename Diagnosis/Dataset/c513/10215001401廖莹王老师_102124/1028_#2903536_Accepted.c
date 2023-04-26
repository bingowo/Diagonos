#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int cmp2(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    char xuhao;
    int h=0;
    int a[10000]={0},t[10000]={0};
    scanf("%c",&xuhao);
    while( scanf("%d",&a[h])!=EOF)h++;
    int i,count=0,j=0,k=0,l=0;
    t[k]=a[0];
    for(i=1;i<h;i++)
    {
        count=0;
        for(j=0;j<=k;j++){if(a[i]==t[j])count=0;if(a[i]!=t[j])count++;}
        if(count==k+1){k++;t[k]=a[i];}

    }
    if(xuhao=='A')qsort(t,k+1,sizeof(t[0]),cmp1);
    else if(xuhao=='D')qsort(t,k+1,sizeof(t[0]),cmp2);
    for(i=0;i<k;i++)printf("%d ",t[i]);
    printf("%d",t[i]);
    return 0;
}
