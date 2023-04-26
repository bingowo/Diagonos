#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
                printf("%d",B[j]);
                C[k]=B[j];
                k=k+1;
            }
        }
    }
    int D[m+n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(B[i])
        }
    }
    
}