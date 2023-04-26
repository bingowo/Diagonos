#include<stdio.h>
#include<stdlib.h>
int cmp(const void* A, const void* B)
{
    long long int* a = (long long int*) A;
    long long int* b = (long long int*) B;
    long long int a1=*a;
    long long int b1=*b;
    int l1=0;
    int l2=0;
    int k = 0;
    while(a1!=EOF)l1++;a1++;
    while(b1!=EOF)l2++;b1++;
    if(l1==l2)
    {
        if(*a>*b)
            return 1;//a所指的元素排在b所指元素的右边
        else
            return -1;//左边
    }
    else
        return l2-l1;//按1的数目来排序

}
int main()
{
    long long int a[100000];
    while(scanf("%lld",a+j)!=EOF){
        qsort(a, n, sizeof(long long int), cmp);
        printf("%lld%c",a[j],j!=n-1?' ':'\n');
    }
    return 0;
}