#include <stdio.h>
#include <stdlib.h>
#define N 11

int measurable(int target, const int weights[N], int index, const int n){
    if(target == 0) return 1;
    if(index >= n) return 0;
    return (measurable(target+weights[index],weights,index+1,n)
            ||measurable(target,weights,index+1,n)
            ||measurable(target-weights[index],weights,index+1,n));
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d",&n);
    int weights[N] = {0};

    int sum = 0;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        weights[i] = temp;
        sum += temp;
    }

    qsort(weights,n,sizeof(weights[0]),cmp);//asc sort

    for(int i = 1; i <= sum; i++){
        int temp = measurable(i,weights,0,n);
        printf("%d",temp);
    }

    return 0;
}

