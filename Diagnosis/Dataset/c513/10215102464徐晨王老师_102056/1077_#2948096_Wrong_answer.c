#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b){
    return *(int*)a>*(int *)b;
}

int main(){
    int m;
    scanf("%d",&m);
    int A[m];
    for(int i=0;i<m;i++){
        scanf("%d",&A[i]);
    }
    int n;
    scanf("%d",&n);
    int B[n];
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    int C[m+n];
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(B[j]==A[i]){
                printf("%d ",B[j]);
                C[k]=B[j];
                k=k+1;
            }
        }
    }
    /*int D[k];
    int flag=1;
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(B[i]==C[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            D[len]=B[i];
            len=len+1;
        }
        flag=1;
    }
    qsort(D,len,sizeof(D[0]),cmp);
    for(int i=0;i<len;i++){
        printf("%d ",D[i]);
    }*/
    return 0;
}