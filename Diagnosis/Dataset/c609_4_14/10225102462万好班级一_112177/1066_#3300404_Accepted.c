#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int num;
int arr[10];
int dfs(int i,int sum,int tar){
    if(i == num) return tar == sum;
    if(dfs(i+1,sum,tar)) return 1;
    if(dfs(i+1,sum + arr[i],tar)) return 1;
    if(dfs(i+1,sum - arr[i],tar)) return 1;
    return 0;
}


int main(){
    scanf("%d",&num);int ssu = 0;
    for (int i = 0; i < num; ++i){scanf("%d",&arr[i]);ssu += arr[i];}
    for (int i = 1; i < ssu+1; ++i) {
        printf("%d",dfs(0,0,i));
    }
}