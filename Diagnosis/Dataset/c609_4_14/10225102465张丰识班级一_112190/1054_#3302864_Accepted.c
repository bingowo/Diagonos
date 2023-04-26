#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    int v[400];
}BIGINT;

void div2(BIGINT *a){
    int carry=0;
    if(a->v[a->num-1]<2)
        a->num--,carry=1;
    for(int i=a->num-1;i>=0;i--){
        int t=carry*10+a->v[i];
        a->v[i]=t/2;
        carry=t%2;
    }
}

void mul(BIGINT *t,int a){
    int carry = 0;
    int len = t->num;
    int pre;
    for(int x = 0;x < len;x++){
        pre = t->v[x] * a + carry;
        t->v[x] = pre % 10;
        carry = pre / 10;
    }
    while(carry){
        t->v[t->num] = carry % 10;
        carry = carry / 10;
        t->num++;
    }
}

void add1(BIGINT *a){
    int i=1;
    a->v[0]=a->v[0]+1;
    int carry=a->v[0]/10;
    a->v[0]=a->v[0]%10;
    while(carry!=0&&i<a->num){
        a->v[i]+=carry;
        carry=a->v[i]/10;
        a->v[i]=a->v[i]%10;
        i++;
    }
    if(carry!=0){
        a->v[i]=carry;
        a->num++;
    }
}

void trans(BIGINT *ans,char a[]){
    int len = strlen(a);
    ans->num = len;
    for(int i = 0,j = len-1;i < len;i++,j--)
        ans->v[i] = a[j] - '0';
}

int main(){
    int T;
    scanf("%d\n",&T);
    for(int i = 0;i < T;i++){
        BIGINT a = {0,{0}};
        BIGINT ans = {0,{0}};
        char s[106];
        scanf("%s",s);
        trans(&a,s);
        if(a.num == 1 && a.v[0] == 0) printf("case #%d:\n0\n",i);
        else{
            while(a.v[0] % 2 == 0) div2(&a);
            ans.num = 1;
            ans.v[0] = 1;
            div2(&a);
            while(a.num != 0 || a.v[a.num - 1] != 0){
                mul(&ans,2);
                if(a.v[0] % 2) add1(&ans);
                div2(&a);
            }
            printf("case #%d:\n",i);
            for(int t = ans.num-1;t >= 0;t--)
                printf("%d",ans.v[t]);
            printf("\n");
        }
    }
}