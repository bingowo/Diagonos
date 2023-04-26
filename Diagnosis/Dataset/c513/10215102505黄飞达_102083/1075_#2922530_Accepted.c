#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long



ll llmin(ll a, ll b){
    return a < b ? a : b;
}

int main(){
    int M=0, N=0;
    scanf("%d %d ", &M, &N);
    ll arr[205][205] = {0}, memory[205][205] = {0}; 
    for (int i = 0; i < 201; i++) {//围一圈很大的数字
        arr[i][0] = 0xffffff;
        arr[i][N+1] = 0xffffff;
        arr[0][i] = 0xffffff;
        arr[M+1][i] = 0xffffff;
        memory[i][0] = 0xffffff;
        memory[i][N+1] = 0xffffff;
        memory[0][i] = 0xffffff;
        memory[M+1][i] = 0xffffff;
    }
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%lld", &arr[i][j]);
        }
    }
    memory[M][N] = arr[M][N];
    for (int i = M-1; i >= 0; i--) memory[i][N] += arr[i][N] + memory[i+1][N];
    for (int i = N-1; i >= 0; i--) memory[M][i] += arr[M][i] + memory[M][i+1];
    for (int i = M-1; i >= 0; i--) {
        for (int j = N-1; j >= 0; j--) {
            memory[i][j] = arr[i][j] + llmin(memory[i+1][j], memory[i][j+1]);
        }
    }
    printf("%lld\n", memory[1][1]);
    char road[500] = {0};
    int x = 1, y = 1;
    for (int i = 0; i < M+N-2; i++){
        if (memory[x+1][y] < memory[x][y+1]) {
            road[i] = 'D';
            x += 1;
        }
        else if (memory[x+1][y] > memory[x][y+1]){
            road[i] = 'R';
            y += 1;
        }
        else {printf("???");break;}
    }
    for (int i = 0; i < M+N; i++) printf("%c", road[i]);


    return 0;
}