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
int cmn(int n)
{
    int r=0;
    if(n>0){
        while(n){
            if((n&1)==1)) r++;
            else r=r;
            n>>=2;
        }
    }
    else if(n=0) r=0;
    else{
        r+=1;
        n=(~n)+1;
        while(n){
            if((n&1)==1)) r++;
            else r=r;
            n>>=2;
    }
    return r;
}
int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    for(i=0;i<T;i++){
        int N,a[N];
        scanf("%d\n",&N);
        int j=0;
        for(j=0;j<N;j++){
            scanf("%lld\t",a[j]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n");
        for(j=0;j<N;j++){
            printf("%lld",a[j]);
        }
        printf("\n");
        }
    return 0;
}

int main()
{
    
}