#include<stdio.h>
#include<string.h>

int num[1005], res[1005];
int len=0;

int dfs(int d, int sum, int flag){
    if (d>=len) {
        if (sum%9==0) return 0;
        else return 1;
    }
    int min_num=flag?num[d]:0;
    if (d==len-1 && min_num==num[d]) min_num++;
    for (int i=min_num; i<9; i++){
        sum += i;
        res[d]=i;
        if (dfs(d+1, i, flag&&(i==min_num))==1) return 1;
    }
    return 0;
}

int main(){
// while(1){
//     memset(num,0,100);memset(res,0,400);len=0;

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
// }
    return 0;
}