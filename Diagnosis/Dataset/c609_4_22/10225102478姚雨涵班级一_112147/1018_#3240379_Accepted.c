#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int main(){
    int n;
    scanf("%d",&n);
    int in[n];
    for(int i = 0;i<n;i++)
        scanf("%d",&in[i]);
    qsort(in,n,sizeof(int),cmp);
    int temp[n/2],sum = 0;
    int k = 1;
    for(int i = 0;i<n/2;i++){
        temp[i] = in[k] - in[k-1];
        if(temp[i]<0)
            temp[i] = -temp[i];
        k += 2;
        sum += temp[i];
    }
    printf("%d",sum);
    return 0;
}
