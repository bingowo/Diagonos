#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numOfOne;
    long int num;
} DATA;


int countOne(long int a){
    long int com=1;
    int res=0;
    for(int i=0;i<64;i++){
        if((a&com)!=0) res++;
        com=com<<1;
    }
    return res;
}

int cmp(void *a,void *b){
    int q,w,e,r;
    q=countOne(*(long int*)a);
    w=countOne(*(long int*)b);
    e=*(long int*)a;
    r=*(long int*)b;

    if(q>w) return -1;
    if(q<w) return 1;
    if(e>r) return 1;
    if(e<r) return -1;
    return 0;
}

int main()
{
    int T,R;
    scanf("%d",&T);

    for(R=0;R<T;R++){
        printf("case #%d:\n",R);

        int N;
        scanf("%d",&N);

        long int *or;
        or=(long int*)malloc(N*sizeof(long int));
        for(int i=0;i<N;i++){
            scanf("%ld",&or[i]);
        }

        qsort(or,N,sizeof(long int),cmp);

        printf("%ld",or[0]);
        for(int i=1;i<N;i++){
            printf(" %ld",or[i]);
        }
        printf("\n");
        free(or);
    }
    return 0;
}
