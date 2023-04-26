#include <stdio.h>
#include <stdlib.h>
#define N 1000

typedef struct{
    int cnt;
    int v[N];
}BIGINT;

BIGINT MUL(BIGINT R,int a){
    int carry=0,j,t;
    for(j=0;j<R.cnt;j++){
        t=R.v[j]*a+carry;
        R.v[j]=t%10;
        carry=t/10;
    }
    while(carry>0){
        R.v[R.cnt++]=carry%10;
        carry/=10;
    }
    return R;
}

void printBIGINT(BIGINT R){
    for(int i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]);
}

int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int a,n,j;
        BIGINT ans={1,{1}};
        printf("case #%d:\n",i);
        scanf("%d%d",&a,&n);
        for(j=0;j<n;j++)    ans=MUL(ans,a);
        printBIGINT(ans);
        printf("\n");
    }
    return 0;
}
