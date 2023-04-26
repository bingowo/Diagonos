#include<stdio.h>
#include<stdlib.h>
int in(int a[],int t,int m){
    for(int i=0;i<m;i++){
        if(a[i]==t){
            return i;
        }
    }
    return -1;
}
int cmp(const void *a,const void *b){
    return *(int*)a>*(int*)b?1:-1;
}
int main(){
    int m;
    scanf("%d",&m);getchar();
    int *a=(int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    int n;
    scanf("%d",&n);getchar();
    int *b=(int*)malloc(sizeof(int)*n);int diff=0;
    int c[500];int inter=0;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(in(a,t,m)!=-1){
            c[inter++]=in(a,t,m);
        }
        else{
            b[diff++]=t;
        }
    }
    qsort(b,diff,sizeof(int),cmp);
    qsort(c,inter,sizeof(int),cmp);
    for(int i=0;i<inter;i++){
        printf("%d ",a[c[i]]);
    }
    for(int i=0;i<diff;i++){
        printf("%d ",b[i]);
    }
}