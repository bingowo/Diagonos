#include<stdio.h>
#include<string.h>
char num[105]={0};
int res[105]={0};

int b=1;
int dfs(int d, int pre, int flag, int len){
    if (d>=len) {
        b=-1;
        return 1;
    }
    int min_num = flag?(num[d]-'0'):0;
    if (d==len-1 && flag && min_num==num[d]-'0') {
        min_num++; 
        if (min_num>=10) return 0;
    }
    for (int i=min_num; i<=9; i++){
        if (i==pre) continue;
        else if (b==-1) return 1;
        res[d] = i;
        if (dfs(d+1, i, flag&&(i==min_num), len)==1) return 1;
    }
    return 0;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        memset(num, 0, 105);
        memset(res, 0, 105);
        b=1;
        printf("case #%d:\n", t);
        gets(num);
        int len = strlen(num);
        if (dfs(0, -1, 1, len)==0) {
            for (int i=1; i<=len+1; i++) printf("%d", i%2);
            printf("\n");
        }
        else {
            for (int i=0; i<len; i++) printf("%d", res[i]);
            printf("\n");            
        }
    }
    return 0;
}