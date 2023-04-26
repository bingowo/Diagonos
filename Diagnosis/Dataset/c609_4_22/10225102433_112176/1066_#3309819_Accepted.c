#include <stdio.h>
#include <math.h>

int f[11];
int ans[1010];
int n;

void dfs(int idx,int num)
{
    if(idx > n) return;
    ans[num]++;
    dfs(idx+1,num);
    dfs(idx+1,abs(num-f[idx+1]));
    dfs(idx+1,num+f[idx+1]);
}

int main()
{
    int sum = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&f[i]);
        sum += f[i];
    }
    dfs(0,0);
    for(int i = 1;i <= sum;i++){
        if(ans[i] >= 1) printf("1");
        else printf("0");
    }
    return 0;
}