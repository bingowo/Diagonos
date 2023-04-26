#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int cmp2(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
void paixu(int h)
{
    int n,i;
    int a[1100]={0},b[1100]={0};
    int sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    qsort(a,n,sizeof(a[0]),cmp1);
    qsort(b,n,sizeof(b[0]),cmp2);
    for(i=0;i<n;i++)
        sum=sum+a[i]*b[i];
    printf("case #%d:\n",h);
    printf("%d\n",sum);

}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        paixu(h);
}
