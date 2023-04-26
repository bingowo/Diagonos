#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int b;
    int pos;
}B;
int searchBinA(int num, int A[], int m){
    for(int i=0; i<m; i++) 
        if(A[i]==num) return i;
    return -1;    
}
int cmp1(const void *a, const void *b){
    B x1=*(B*)a, x2=*(B*)b;
    if(x1.pos!=-1 && x2.pos!=-1) return x1.pos-x2.pos;
    else if(x1.pos==-1 && x2.pos!=-1) return 1;
    else if(x1.pos!=-1 && x2.pos==-1) return -1;
    else return x1.b-x2.b;
}
int main(){
    int m, n;
    scanf("%d", &m);
    int *A;
    B *nums;
    A = (int*)calloc(m,sizeof(int));
    for(int i=0; i<m; i++)
        scanf("%d", &A[i]);
    scanf("%d", &n);
    nums = (B*)malloc(sizeof(B)*n);
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i].b);
        nums[i].pos = searchBinA(nums[i].b, A, m);
    }
    qsort(nums, n, sizeof(nums[0]), cmp1);
    for(int i=0; i<n-1; i++) printf("%d ", nums[i].b);
    printf("%d", nums[n-1].b);
    free(nums);
    free(A);
    return 0;
}