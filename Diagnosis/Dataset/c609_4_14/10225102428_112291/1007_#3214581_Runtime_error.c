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
    for(k=0;k<64;k++)
    {
        if (((a1>>k) & 1 == 1))l1++;
        if (((b1>>k) & 1 == 1))l2++;
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

void Sort(int *p, int n)
{
    qsort(p, n, sizeof(int), cmp);
}

int main()
{ 
        int t,i;
        scanf("%d",&t);
        for (i=0;i<t;i++){
            long long int a[1000],n;
            scanf("%lld",n);
            for(int j=0;j<n;j++){
                scanf("%lld",a+i);Sort(a,n);
                printf("case #%d:\n",i);
                printf("%lld%c",a[i],i!=n-1?' ':'\n');
            }
            
        } 
        return 0;
}