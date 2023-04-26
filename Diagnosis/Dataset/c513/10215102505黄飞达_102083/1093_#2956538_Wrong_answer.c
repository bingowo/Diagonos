#include<stdio.h>
#include<string.h>

int num[105], res[105];
int len=0;

int dfs(int d, int sum, int flag){
    if (d>=len) return 1;
    int min_num=flag?num[d]:0;
    if (d==len-1 && min_num==num[d]) min_num++;
    for (int i=min_num; i<9; i++){
        if ((sum+i)%9==0) continue;
        sum += i;
        res[d]=i;
        if (dfs(d+1, i, flag&&(i==min_num))==1) return 1;
    }
    return 0;
}

int main(){
    char s[1005]={0};
    gets(s);
    int slen=strlen(s);
    while(len<slen){
        num[len]=s[len]-'0';
        len++;
    }
    if (dfs(0, 0, 1)==0){
        printf("1");
        for (int i=1; i<=len; i++) printf("0");
        printf("\n");
    }
    else {
        for (int i=0; i<len; i++) printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}