//1074  dfs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXH 1000000007
int num[110], count;
void dfs(long long sum, long long ret, int pos, int n){
    if(pos==n){
        //printf("%d\n", sum+ret);
        if((sum+ret)%2==0 || (sum+ret)%3==0) count++;
        return;
    }
    //pos位置前用+
    dfs(sum+ret, num[pos], pos+1, n);
    //pos位置前用-
    dfs(sum+ret, num[pos]*-1, pos+1, n);
    //pos位置前用...
    if(ret<0)
        dfs(sum, ret*10-num[pos], pos+1, n);
    else
        dfs(sum, ret*10+num[pos], pos+1, n);
}
int main(){
    int n, len1;
    char s[110];
    scanf("%d", &n);
    for(int t=0; t<n; t++){
        scanf("%s", s);
        memset(num, -1, sizeof(num));
        len1 = strlen(s);
        count = 0;
        for(int i=0; i<len1; i++) num[i] = (int)s[i]-48;//存入数组中
        dfs(0, num[0], 1, len1);//开始深搜
        printf("%d\n", count%MAXH);
    }
    return 0;
}