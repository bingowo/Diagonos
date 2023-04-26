#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int line[51];
    int len;
} LINE;

int cmp(const void* p3,const void* p4)
{
    LINE* p1=(LINE* )p3;
    LINE* p2=(LINE* )p4;
    for(int i=0;i<((p1->len)<(p2->len) ? (p1->len):(p2->len));i++){
        if((p1->line[i])<(p2->line[i])) return 1;
        else if((p1->line[i])>(p2->line[i])) return -1;
    }
    if((p1->len)<(p2->len)) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        LINE* p=(LINE* )malloc(n*sizeof(LINE));
        for(int i=0;i<n;i++){
            int nn=0,data=0;
            do{
                scanf("%d",&data);
                if(data!=-1){
                    (p+i)->line[nn]=data;
                    nn++;
                }
                else (p+i)->len=nn;
            }while(data!=-1);
        }
        qsort(p,n,sizeof(LINE),cmp);
        for (int ii=0;ii<n;ii++){
            for(int k=0;k<((p+ii)->len);k++) printf("%d ",(p+ii)->line[k]);
            printf("\n");
        }
        free(p);
    }
    return 0;
}
