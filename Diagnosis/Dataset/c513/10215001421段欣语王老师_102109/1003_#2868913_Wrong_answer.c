#include <stdio.h>
#include <stdlib.h>

int countOne(long long int a)
{
    long long int com=1;
    int res=0;
    for(int i=0;i<64;i++){
        if(a&com) res++;
        com=com<<1;
    }
    return res;
}

int cmp(void *a,void *b){
    int q,w,e,r;
    q=countOne(*(long long int*)a);
    w=countOne(*(long long int*)b);
    e=*(long long int*)a;
    r=*(long long int*)b;

    if(q>w) return -1;
    if(q<w) return 1;
    if(e<r) return 1;
    if(e>r) return -1;
}

int main()
{
    int T,R;
    scanf("%d",&T);

    for(R=0;R<T;R++)
        {
        printf("case #%d:\n",R);

        int N;
        scanf("%d",&N);

        long long int *or;
        or=(long long int*)malloc(N*sizeof(long long int));
        for(int i=0;i<N;i++)
            {
            scanf("%lld",&or[i]);
        }

        qsort(or,N,sizeof(long long int),cmp);

        printf("%lld",or[0]);
        for(int i=1;i<N;i++){
            printf(" %lld",or[i]);
        }
        printf("\n");
        free(or);
    }
    return 0;
}