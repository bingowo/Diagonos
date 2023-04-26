#include<stdio.h>
#include<stdlib.h>
int cmp(const void *p1,const void *p2);

int main(void)
{
    int n;
    scanf("%d",&n);
    int input[n];

    for(int i = 0; i < n; i++){
        scanf("%d",&input[i]);
    }

    long long sum;
    qsort(input,n,sizeof(int),cmp);

    for(int i = 0; i < n; i += 2){
        sum += input[i] - input[i+1];
    }

    printf("%lld",sum);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    int a = *(int*)p1;
    int b = *(int*)p2;
    return a < b?1:a > b?-1:0;
}