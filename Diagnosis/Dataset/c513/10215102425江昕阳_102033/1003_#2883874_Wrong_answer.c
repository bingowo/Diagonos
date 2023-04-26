#include <stdio.h>
#include <stdlib.h>

typedef struct{long long int x;int y;}num;

int cmp(const void* a,const void* b){
int n1,N1,n2,N2;num *a1=(num*)a,*b1=(num*)b;
n1=a1->x;
N1=a1->y;
n2=b1->x;
N2=b1->y;
if(N1==N2)return n1-n2;
else if(N2>N1) return 1;
else return -1;
}

int main()
{int T,N;num t,*p,*p1;
scanf("%d",&T);
for(int i=0;i<T;i++){
    scanf("%d",&N);
    p=p1=(num*)malloc(N*sizeof(num));
    for(int j=0;j<N;j++){
        scanf("%lld",&((p1+j)->x));
        if((p1+j)->x<0)(p1+j)->y=1;
        else (p1+j)->y=0;
        for(int k=0;k<63;k++){
            if(((p1+j)->x>>k)&1ll==1ll)(p1+j)->y++;
        };
    };
    qsort(p1,N,sizeof(num),cmp);
    printf("case #%d:\n",i);
    for(int j=0;j<N;j++){
        printf("%lld ",(p+j)->x);
    };
    printf("\n");
    free(p);
}
    return 0;
}
