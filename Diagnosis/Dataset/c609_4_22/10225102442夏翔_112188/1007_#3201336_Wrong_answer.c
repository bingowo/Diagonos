#include<stdio.h>
#include<stdlib.h>
typedef struct{
    long long num;
    int count;
}NUM;
int f(long long n){
    int count=0;
    unsigned long temp=n;
    while(temp!=0){
        if(temp%2==1) count++;
        temp /= 2;
    }
    return count;
}

int cmp1(const void *a, const void *b){
    NUM x1=*(NUM*)a, x2=*(NUM*)b;
    if(x1.count!=x2.count) return x2.count-x1.count;
    return x1.num-x2.num;
}
int main(){
    int T, N;
    scanf("%d", &T);
    NUM* nums;
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        nums = (NUM*)malloc(sizeof(NUM)*N);
        for(int j=0; j<N; j++){
            scanf("%lld", &nums[j].num);
            nums[j].count = f(nums[j].num);
        }
        qsort(nums,N,sizeof(nums[0]),cmp1);
        printf("case #%d:\n", i);
        for(int j=0; j<N; j++){
            printf("%lld ", nums[j].num);
        }
        printf("%c", '\n');
        free(nums);
    }
    return 0;
}
