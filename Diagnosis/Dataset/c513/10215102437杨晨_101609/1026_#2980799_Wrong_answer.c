#include<stdio.h>
#include <stdlib.h>
int cmp(const void *a, void *b);
int main(){
    int T;
    scanf("%d",&T);
    int t[T];
    for(int i=0; i<T;i++){
        scanf("%d",&t[i]);
    }
    qsort(t,T-1,sizeof(int),cmp);
    int n=0;
    for (int i=0;i<=T-1;i=i+2){
        n=n+t[i+1]-t[i];
    }
    printf("%d",n);
    return 0;

	}
int cmp(const void *a, void *b){
    int m=*(int*)a;
    int n=*(int*)b;
    return m-n;
    }