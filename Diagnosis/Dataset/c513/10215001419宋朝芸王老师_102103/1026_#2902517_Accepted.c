#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void *a, const void *b){
    long long int *pa = (long long int*)a, *pb = (long long int*)b;

    return (*pa - *pb);
}

int main()
{
    int n;
    scanf("%d",&n);

    long long int *input = (long long int*)malloc(n*sizeof(long long int));
    for(int k = 0; k < n; k++){
        scanf("%lld",&input[k]);
    }

    qsort(input,n,sizeof(long long int),cmp);


    long long int ans = 0;
    for(int k = 0; k < n; k += 2){
        ans += input[k+1] - input[k];
    }

    printf("%lld",ans);

    return 0;
}
