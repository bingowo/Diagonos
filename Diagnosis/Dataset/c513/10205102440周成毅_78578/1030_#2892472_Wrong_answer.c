#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Number{
    long long data;
    int bit;
}number;

void compute(number *a){
    char str[256];
    sprintf(str,"%lld",a->data);
    if(a->data>=0)
        a->bit=str[0]-'0';
    else
        a->bit=-(str[1]-'0');
}

int cmp(const void *a, const void *b){
    number *a1=(number *)a;
    number *b1=(number *)b;
    if(a1->bit!=b1->bit)
        return b1->bit-a1->bit;
    else
        return a1->data-b1->data;
}

int main() {
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        number *list=(number *) malloc(sizeof (number)*N);
        for(int j=0;j<N;j++){
            scanf("%lld",&list[j].data);
            compute(&list[j]);
        }
        qsort(list,N,sizeof (number),cmp);
        for(int j=0;j<N;j++)
            printf("%lld ",list[j].data);
        printf("\n");
    }
    return 0;
}
