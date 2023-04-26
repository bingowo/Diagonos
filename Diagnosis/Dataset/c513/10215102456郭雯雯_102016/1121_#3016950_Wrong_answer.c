#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    int c=*(int*)a,d=*(int*)b;
    return c-d;
}

int main(){
    int n;
    scanf("%d",&n);
    int w[n],sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    int ans[sum];
    for(int i=0;i<sum;i++)ans[i]=0;
    qsort(w,n,sizeof(int),cmp);
}