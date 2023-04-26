#include<stdio.h>
#include<stdlib.h>
int cmp(const void *p1,const void *p2);

int main(void)
{
    int n;
    scanf("%d",&n);
    unsigned long input[n];

    for(int i = 0; i < n; i++){
        scanf("%lu",&input[i]);
    }

    unsigned long long sum;
    qsort(input,n,sizeof(unsigned long),cmp);

    for(int i = 0; i < n; i += 2){
        sum += input[i] - input[i+1];
    }

    printf("%llu",sum);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    unsigned long a = *(unsigned long*) p1;
    unsigned long b = *(unsigned long*)p2;
    return a < b?1:a > b?-1:0;
}