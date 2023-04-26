#include<stdio.h>
#include<stdlib.h>
int cmp(const void* A, const void* B)
{
    int* a = (int*) A;
    int* b = (int*) B;
    int a1=*a;
    int b1=*b;
    int l1=0;
    int l2=0;
    int k = 0;
    for(k=0;k<32;k++)
    {
        if (((a>>k) & 1 == 1))l1++;
        if (((b>>k) & 1 == 1))l2++;
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
            int a[1000],n;
            scanf("%d",n);
            for(int j=0;j<n;j++){
                scanf("%d",a+i);Sort(a,n);
                printf("case #%d:\n",i);
                printf("%d%c",a[i],i!=n-1?' ':'\n');
            }
            
        } 
        return 0;
}