#include<stdio.h>

int N = 50;
int input(int (*p)[N]){
    int index = 0;
    do{
        int temp, i = N;
        scanf("%d", &temp);
        do{
            p[index++][--i] = temp % 10;
            p[index][--i] = temp / 10;
        }while(temp /= 10);
    }while(getchar() != '\n');
}

void output(int *res){
    int i = len;
    while(!res[i]) i++;
    for (;i != N; i++)
        printf("%d", res[i]);
    printf("\n");
}

void mult(int *num, int prime){
    for (int i = N - 1; num[i] != 0; i--)
        num[i] *= prime;
    for (int i = N - 1; num[i] != 0; i--){
        num[i] %= 10;
        num[i-1] += num[i] / 10;
    }
}

void add(int *res, int *num){
    for (int i = N - 1; num[i] != 0; i--)
       res[i] += num[i];
    for (int i = N - 1; res[i] != 0; i--){
        res[i] %= 10;
        res[i - 1] += res[i] / 10;
    }
}

int main(){
    int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int nums[25][N] = {0};
    int res[N];
    
    int len = input(nums);
    for (int i = 0; i != len; i++){
        for (int j = 0; j != len - 1 - i; j++)
            mult(nums[i], prime[j]);
        add(res, nums[i]);
    }
    output(res);
    return 0;
}