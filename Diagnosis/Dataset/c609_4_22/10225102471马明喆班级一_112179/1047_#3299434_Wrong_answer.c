#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int s[106];
    int num;
}BIGINT;

void mul(BIGINT *t,int a){
    int carry = 0;
    int len = t->num;
    int pre;
    for(int x = 0;x < len;x++){
        pre = t->s[x] * a + carry;
        t->s[x] = pre % 10;
        carry = pre / 10;
    }
    while(carry){
        t->s[t->num] = carry % 10;
        carry = carry / 10;
        t->num++;
    }
}

void trans(BIGINT *ans,int a){
    for(int t = 0;t < 106;t++) ans->s[t] = 0;
    ans->num = 0;
    while(a){
        ans->s[ans->num++] = a % 10;
        a = a / 10;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int a,n;
        scanf("%d %d\n",&a,&n);
        BIGINT ans;
        trans(&ans,a);
        if(n) {
            for (int q = 0; q < n; q++)
                mul(&ans, a);
        }
        else{
            ans.num = 1;
            ans.s[0]=1;
        }
        printf("case #%d:\n",i);
        for(int m = ans.num - 1;m >= 0;m--){
            printf("%d",ans.s[m]);
        }
        printf("\n");
    }
    return 0;
}