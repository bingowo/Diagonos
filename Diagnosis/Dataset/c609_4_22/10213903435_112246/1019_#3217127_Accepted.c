#include<stdlib.h>
#include<stdio.h>
int cmp(const void *a,const void *b)
{
    int m=*(int *)a,n=*(int*)b;
    int sgn=m>n?1:-1;
    int bcnt_m=0,bcnt_n=0;
    do{bcnt_m++;}while(m/=10);
    do{bcnt_n++;}while(n/=10);
    //printf("\n%d\n",n);
    if(bcnt_m==bcnt_n)return sgn;
    else return bcnt_n-bcnt_m;
}
int main()
{
    int *a;
    int i=0;
    a=(int *)malloc(sizeof(int)*1000000);
    while(scanf("%d",&a[i])!=EOF)i++;
    qsort(a,i,sizeof(int),cmp);
    for(int j=0;j<i;j++)
        printf("%d ",a[j]);
    free(a);
    return 0;
}
