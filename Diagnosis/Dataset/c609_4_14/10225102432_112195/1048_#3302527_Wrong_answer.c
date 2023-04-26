#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150
typedef struct{
    int cnt;
    int ans[N];
} big;

big solve(int n){
    big a1={1,{1}},a2={1,{1}},t={1,{0}};
    int carry=0,i,j,temp;
    if(n==0) {return t;}
    if(n==1||n==2) {return a1;}
    for(i=3;i<=n;i++){
        for(j=0;j<N;j++){
            temp=a1.ans[j]+a2.ans[j]+carry;
            t.ans[j]=temp%10;
            carry=temp/10;
        }
        for(j=0;j<N;j++)
            a1.ans[j]=a2.ans[j];
        for(j=0;j<N;j++)
            a2.ans[j]=t.ans[j];
    }
    return t;
}

int main(){
    int t,i,j;
    scanf("%d",&t);
    int n;
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        big g;
        g=solve(n);
        printf("case #%d:\n",i-1);
        if(n==0) {printf("0");continue;}
        for(j=N-1;j>=0;j--){
            if(g.ans[j]!=0) break;
        }
        while(j>=0){
            printf("%d",g.ans[j]);
            j--;
        }
        printf("\n");
    }
    return 0;
}

