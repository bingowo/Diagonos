#include<stdio.h>

#define N 50
int input(int (*p)[N]){
    int index = 0;
    do{
        scanf("%d", &p[index++][N-1]);
    }while(getchar() != '\n');
    return index;
}

void output(int *res){
    int i = 0;
    while(i != N && res[i] == 0) i++;
    if (i == N){printf("0\n"); return;}
    while (i != N)
        printf("%d", res[i++]);
    printf("\n");
}

void mult(int *num, int prime){
    for (int i = N - 1; i > 0; i--)
        num[i] *= prime;
    for (int i = N - 1; i > 0; i--){
        num[i-1] += num[i] / 10;
        num[i] %= 10;
    }
}

void add(int *res, int *num){
    for (int i = N - 1; i > 0; i--){
        res[i] += num[i];
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }
}

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
    int nums[25][N] = {0};
    int res[N] = {0};

    int len = input(nums);
    for (int i = 0; i != len; i++){
        for (int j = 0; j != len - 1 - i; j++)
            mult(nums[i], prime[j]);
        add(res, nums[i]);
    }
    output(res);
    return 0;
}
