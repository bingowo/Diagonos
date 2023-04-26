#include<stdio.h>
#include<string.h>
typedef struct{
    int num[500];
    int p;
}bint;
bint init(char* s){
    bint ret={{0},0};
    for(int i=strlen(s)-1;i>=0;i--){
        ret.num[ret.p++]=s[i]-'0';
    }
    return ret;
}
bint dp[45][45];
void add(bint* ret,bint*a,bint*b){
    int i=0,carry=0;
    for(;i<a->p || i<b->p || carry!=0;i++){
        int tmp=a->num[i]+b->num[i]+carry;
        ret->num[i]=tmp%10;
        carry=tmp/10;
    }
    ret->p=i;
}
int main(){
    int pro;scanf("%d",&pro);
    for(int i=0;i<=40;i++){
        dp[i][0].num[0]=1;dp[i][0].p=1;
        dp[i][i].num[0]=1;dp[i][i].p=1;
    }
    for(int i=2;i<=40;i++){
        for(int j=1;j<i;j++){
            add(&dp[i][j],&dp[i-1][j-1],&dp[i-1][j]);
        }
    }
    for(int index=0;index<pro;index++){
        int m,n;scanf("%d%d",&m,&n);
        printf("case #%d:\n",index);
        for(int i=dp[m][n].p-1;i>=0;i--)printf("%d",dp[m][n].num[i]);
        printf("\n");
    }
    return 0;
}
