#include<stdio.h>
#include<string.h>
#include<math.h>
int comp1(const void *a,const void *b)//经过此次排列之后从大到小；
{
    int a1=*(int *)a,b1=*(int *)b;
    return b1-a1;
}
int comp2(const void *a,const void *b)//从小到大；
{
    int a1=*(int *)a,b1=*(int *)b;
    return a1-b1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int dim;
        scanf("%d",&dim);
        int a[dim],b[dim];
        for(int m=0;m<dim;m++)scanf("%d",&a[m]);
        for(int m=0;m<dim;m++)scanf("%d",&b[m]);
        qsort(a,dim,sizeof(int),comp1);
        qsort(b,dim,sizeof(int),comp2);
        long long res=0;
        for(int step=0;step<dim;step++){
            res=res+(a[step]*b[step]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
