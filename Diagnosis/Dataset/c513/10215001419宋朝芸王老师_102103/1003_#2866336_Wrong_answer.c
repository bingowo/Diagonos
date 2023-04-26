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

int cmp(void *a,void *b){
    if(countOne(*(int*)a)==countOne(*(int*)b)) return (b-a);
    else return (countOne(*(int*)b)-countOne(*(int*)a));
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
        qsort(or,N,sizeof(int),cmp);

        printf("%d",or[0]);
        for(int i=1;i<N;i++){
            printf(" %d",or[i]);
        }
        printf("\n");
        free(or);
    }
    return 0;
}
