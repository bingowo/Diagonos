#include <stdio.h>
#include <stdlib.h>
//wrong alg
int cmp(const void *a, const void *b){
    long long int ia = *(long long int*)a, ib = *(long long int*)b;
    if(ia > ib) return 1;
    if(ia < ib) return -1;
    return 0;
}

//a-b + a-c + a-d
//a-c = a-b + b-c

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    long long int* in = (long long int*)malloc(n*sizeof(long long int));
    for(int i = 0; i < n; i++){
        scanf("%lld",&in[i]);
    }

    qsort(in,n,sizeof(in[0]),cmp);  //as

    long long int ans = 0;

    int subscript;//starter
    long long int min = 0, temp = 0;
    for(int i = 0; i < n;i++){
        temp = in[i+m-1] - in[i];
        if(temp < min){
            subscript = i;
            min = temp;
        }
    }

    for(int j = subscript; j < subscript+m-1; j++){
        ans += (in[subscript+m-1] - in[j]);
    }

    printf("%lld",ans);

    return 0;
}
