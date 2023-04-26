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
    qsort(B,n,sizeof(B[0]),cmp);
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(B[i]==C[j])flag=1;
        }
            if(flag){flag=0;continue;}
        else printf("%d ",B[i]);
    }

    return 0;
}
