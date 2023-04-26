//1070 dfs/剪枝/回溯
#include <stdio.h>
#include <string.h>
int count, num[30];
void dfs(int len, int n){
    if(len>=3){
        if(num[len-3]==1 && num[len-2]==0 &&num[len-1]==1) return; //不符合,剪枝
    }
    if(len==n){ //长度到了n，符合条件
        count++;
        return;
    }
    num[len] = 1; 
    dfs(len+1, n);
    num[len] = 0;//回溯的思想
    dfs(len+1, n);
}
int main(){
    int n;
    scanf("%d", &n);
    while(n!=-1){
        memset(num, -1, sizeof(num));
        count = 0;
        dfs(0, n);
        printf("%d\n", count);
        scanf("%d", &n);
    }
    return 0;
}