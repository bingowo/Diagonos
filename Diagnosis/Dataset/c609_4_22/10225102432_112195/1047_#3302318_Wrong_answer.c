#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150
typedef struct{
    int cnt;
    int ans[N];
} big;

big solve(int a,int n){
    int carry=0,i,j,t;
    big b={1,{1}};
    for(i=1;i<=n;i++){
        for(j=0;j<b.cnt;j++){
            t=b.ans[j]*a;
            b.ans[j]=t%10;
            carry=t/10;
        }
        while(carry>0){
            b.ans[b.cnt++]=carry%10;
            carry/=10;
        }
    }
    return b;
}

int main(){
    int t,i;
    scanf("%d",&t);
    int a,n;
    for(i=1;i<=t;i++){
        scanf("%d%d",&a,&n);
        big g;
        g=solve(a,n);
        printf("case #%d:\n",i-1);
        for(int j=g.cnt-1;j>=0;j--){
            printf("%d",g.ans[j]);
        }
        printf("\n");
    }
    return 0;
}
