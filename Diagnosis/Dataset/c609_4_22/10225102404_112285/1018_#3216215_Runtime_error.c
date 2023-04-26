#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void* _a,const void* _b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *a-*b;
}
int main()
{
    int n,k=0,sum=0;
    scanf("%d",&n);
    int b[1001];
    while(scanf("%d",&b[k])!=EOF)
    {
        k++;
    }
    qsort(b,k,sizeof(b[0]),cmp_int);
    for(int i=0;i<k-1;i+=2)
    {
        sum+=b[i+1]-b[i];
    }
    printf("%d",sum);
    return 0;

}
