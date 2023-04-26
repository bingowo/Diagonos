#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int item;
    int count;
}bi;
int** cmp(void)
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
            scanf("%d\t",a[j]);
        }
        }
    return 0;
}

int main()
{
    
}