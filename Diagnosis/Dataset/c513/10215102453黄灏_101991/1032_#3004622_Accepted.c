#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r[50];
}row;

int cmp(const void *a,const void *b){
    row *x=(row*)a,*y=(row*)b;
    int j=0;
    while ((x->r[j] != -1) && (y->r[j]!=-1)){
        if(x->r[j] == y->r[j]) ++j;
        else return y->r[j] - x->r[j];
    }
    if(y->r[j] == -1) return -1;
    else return 1;

}

int main() {
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d\n",&N);
        row data[N];
        for(int m=0;m<N;m++){
            for(int n=0;n<55;n++){
                int temp;
                scanf("%d",&temp);
                if(temp==-1) {data[m].r[n]=temp;break;}
                else data[m].r[n]=temp;
            }
        }
        qsort(data,N,sizeof(row),cmp);
        for(int m=0;m<N;m++){
            for(int n=0;n<50;n++){
                if(data[m].r[n] == -1) break;
                else printf("%d ",data[m].r[n]);
            }
            printf("\n");
        }
    }
    return 0;
}
