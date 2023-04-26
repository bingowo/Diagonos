#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a, const void *b){
    long long *x1=*(long long**)a, *x2=*(long long**)b;
    int pos1=0, pos2=0;
    while(x1[pos1]!=-1 && x2[pos2]!=-1){
        if(x1[pos1]>x2[pos2]) return -1;
        else if(x1[pos1]<x2[pos2]) return 1;
        pos1++;
        pos2++;
    }
    if(x1[pos1]==-1&&x2[pos2]!=-1) return 1;
    if(x1[pos1]!=-1&&x2[pos2]==-1) return -1;
    return 0;
}
int main(){
    int T, N, count;
    scanf("%d", &T);
    long long **num, temp;
    for(int k=0; k<T; k++){
        scanf("%d", &N);
        num = (long long**)malloc(sizeof(long long*)*N);
        for(int i=0; i<N; i++){
            count = 0;
            num[i] = (long long*)malloc(sizeof(long long)*51);
            scanf("%lld", &temp);
            while(temp!=-1){
                num[i][count++] = temp;
                scanf("%lld", &temp);
            }
            num[i][count] = temp;
        }
        qsort(num, N, sizeof(num[0]), cmp1);
        for(int i=0; i<N; i++){
            count = 0;
            while(num[i][count]!=-1){
                printf("%lld ", num[i][count++]);
            }
            printf("%c", '\n');
        }
        for(int i=0; i<N; i++) free(num[i]);
        free(num);
    }
    return 0;
}