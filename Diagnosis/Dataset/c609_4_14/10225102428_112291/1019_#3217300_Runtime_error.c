#include<stdio.h>
#include<stdlib.h>
int cmp(const void* A, const void* B)
{
    long long int* a = (long long int*) A;
    long long int* b = (long long int*) B;
    int l1=0;
    int l2=0;
    int aa=abs(*a);
    int bb=abs(*b);
    if(*a==0){
          l1=0;
    }
    else{
        while(aa){
          aa=aa/10;
          l1++;
        }
    }
    if(*b==0){
          l1=0;
    }
    else{
        while(bb){
          bb=bb/10;
          l2++;
        }
    }
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
    int j=0;
    while(scanf("%lld",a+j)!=EOF){
            j++;
    }
    qsort(a,j, sizeof(long long int), cmp);
    for(int i=0;i<j;i++)printf("%lld%c",a[i],i!=j-1?' ':'\n');
    return 0;
}
