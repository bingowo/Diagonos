//用&，要看哪一位就只把哪一位设成1
//用<<1

#include <stdio.h>
#include <stdlib.h>

int countOne(int a){
    int com=1;
    int res=0;
    for(int i=0;i<64;i++){
        if((a&com)!=0) res++;
        com=com<<1;
    }
    return res;
}

int cmp1(void *a,void *b){
    int q,w,e,r;
    q=countOne(*(int*)a);
    w=countOne(*(int*)b);
    e=*(int*)a;
    r=*(int*)b;

    if(q>w) return -1;
    if(q<w) return 1;
    if(e>r) return 1;
    if(e<r) return -1;
    return 0;
}
int cmp2(void *a,void *b){
    int e,r;
    e=*(int*)a;
    r=*(int*)b;
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

        int *or;
        or=(int*)malloc(N*sizeof(int));
        for(int i=0;i<N;i++){
            scanf("%d",&or[i]);
        }

        qsort(or,N,sizeof(int),cmp2);
        qsort(or,N,sizeof(int),cmp1);

        printf("%d",or[0]);
        for(int i=1;i<N;i++){
            printf(" %d",or[i]);
        }
        printf("\n");
        free(or);
    }
    return 0;
}