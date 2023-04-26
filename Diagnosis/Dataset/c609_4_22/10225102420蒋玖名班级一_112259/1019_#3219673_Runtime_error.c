#include <stdio.h>
#include <stdlib.h>
int dit(int n)
{
    int count=0;
    if(n<0){
        n=-n;
    }
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}
long long cmp(const void * _a, const void * _b)
{
    long long *a=(long long*)_a;
    long long *b=(long long*)_b;
    if(dit(*a)==dit(*b)) return (*(long long*)_a - *(long long*)_b);
    else return (dit(*b)-dit(*a));
}
int main()
{
    int arr[100000];
    int i=0;
    do{
        scanf("%d",&arr[i]);
        i++;
    }
    while((getchar())==' ');
    int size=i;
    qsort(arr,i,sizeof(int),cmp);
    for(int j=0;j<size;j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}
