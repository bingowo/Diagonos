#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef struct{
    long long int item;
    int count;
}bi;
int cmp(const void*a,const void*b){
    bi A=*(bi*)a,B=*(bi*)b;
    if(A.count==B.count)return A.item>B.item?1:-1;
    else return B.count-A.count;
}
int main()
{
    int T;
    scanf("%d",&T);
    int t=0;
    for(t=0;t<T;t++){
        int N;
        scanf("%d\n",&N);
        bi*k;
        k=(bi*)malloc(N*sizeof(bi));
        for(int i=0;i<N;i++){
            scanf("%lld\t",&k[i].item);
            int m=0;
            long long item1=k[i].item;
            while(item1>0){
                if((item1&1)==1)m++;
                item1>>=1;
            }
            if(item1<0){
                int d=64;
                while(d--){
                    if((item1&1)==0)m++;
                    item1>>=1;
                }
                m=64-m;
            }
            k[i].count=m;
        }
        qsort(k,N,sizeof(k[0]),cmp);
        printf("case #%d:\n",t);
        for(int j=0;j<N;j++){
            printf("%lld ",k[j].item);
        }
        printf("\n");
        }
    return 0;
}