#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int bh;
    int jf;
    int sc;
    int fc;
} qd;

int cmp(const void* a,const void* b)
{
    qd* a0=(qd*)a;
    qd* b0=(qd*)b;
    if(b0->jf!=a0->jf)
        return b0->jf-a0->jf;
    if(a0->sc!=b0->sc)
        return b0->sc-a0->sc;
    if(a0->fc!=b0->fc)
        return a0->fc-b0->fc;
    return a0->bh-b0->bh;
}

int main() {
    qd x[10];
    int n,m,a,b,c,i;
    scanf("%d%d",&n,&m);
    while (n!=0 || m!=0){
        for(i=0;i<n;i++){
            x[i].bh=i+1;
            x[i].jf=0;
            x[i].sc=0;
            x[i].fc=0;
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                x[a-1].jf+=3;
                x[b-1].jf-=1;
                x[a-1].sc+=1;
                x[b-1].fc+=1;
            }
            else if(c==-1){
                x[b-1].jf+=3;
                x[a-1].jf-=1;
                x[b-1].sc+=1;
                x[a-1].fc+=1;
            }
            else{
                x[a-1].jf+=1;
                x[b-1].jf+=1;
            }
        }
        qsort(x,n,sizeof(x[0]),cmp);
        for(i=0;i<n;i++){
            printf("%d",x[i].bh);
            if(i==n-1)
                printf("\n");
            else
                printf(" ");
        }
        scanf("%d%d",&n,&m);
    }
    return 0;
}
