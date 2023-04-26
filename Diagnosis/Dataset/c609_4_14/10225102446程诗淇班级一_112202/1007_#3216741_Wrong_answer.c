#include <stdio.h>
#include<stdlib.h>
typedef struct{
    long long int d;
    int c;
} num;
int cmp(const void*a,const void*b){
    int A;
    int B;
    long long int C;
    long long int D;
    A=(*(num*)a).c;
    B=(*(num*)b).c;
    C=(*(num*)a).d;
    D=(*(num*)b).d;
    if(A!=B){
        return B-A;
    }
    else{
        return C-D;
    }



}


int main()
{
    int T,i,m,r,k=0,j,q;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&m);
        num* result=(num*)malloc(m*sizeof(num));

        for(q=0;q<m;q++){
            scanf("%lld",&result[q].d);
            j=0;
            r=0;
            long long int n=1;
            while(j<64){
                if(((result[q].d)&n)!=0){
                    r++;
                }
                n=n<<1;
                j++;
            }
            result[q].c=r;

        }
        qsort(result,m,sizeof(result),cmp);
        printf("case #%d:\n",i);
        for(k=0;k<m;k++){
            printf("%lld ",result[k].d);

        }
        printf("\n");
    }

    return 0;
}
