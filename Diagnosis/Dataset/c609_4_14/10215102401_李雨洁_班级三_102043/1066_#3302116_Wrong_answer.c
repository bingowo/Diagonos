#include <stdio.h>
#include <stdlib.h>
void dfs(int f[], int w[], int pos, int s, int n)
{
    if (s > 0) f[s] = 1; // f[s] 记录重量 s 能否被称出
    if (pos == n) return; // pos 记录当前遍历位置
    dfs(f, w, pos + 1, s, n);
    dfs(f, w, pos + 1, s + w[pos], n);
    dfs(f, w, pos + 1, s - w[pos], n);
}
int main()
{
    int n;
    scanf("%d",&n);
    int w[11];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    int f[100]={0};
    dfs(f,w,0,0,n);
    for(int i=1;i<=sum;i++)
        printf("%d",f[i]);
    printf("\n");
    return 0;
}
