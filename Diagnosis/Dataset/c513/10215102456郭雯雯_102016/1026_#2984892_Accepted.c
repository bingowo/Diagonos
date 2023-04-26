#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    int c=*(int *)a,d=*(int *)b,t;
    t=c-d;
    return t;
}
int main(){
    int n,ans=0;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    qsort(num,n,sizeof(int),cmp);
    for(int i=0;i<n;i+=2){
        ans+=(num[i+1]-num[i]);
    }
    printf("%d",ans);
}