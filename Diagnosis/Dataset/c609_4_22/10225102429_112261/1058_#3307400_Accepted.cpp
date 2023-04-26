#include <stdio.h>
#include <string.h>

typedef struct {
    int cnt;
    int v[101];
}BigInt;

void Div2(BigInt *n){
    int carry = 0;
    if(n->v[n->cnt-1]<2) n->cnt--,carry = 1;
    for(int i = n->cnt-1; i>=0; i--){
        int t = 10*carry + n->v[i];
        n->v[i] = t/2;
        carry = t%2;
    }
}

void Add1(BigInt *n){
    int carry  =0, i = 1;
    n->v[0] = n->v[0]+1; carry = n->v[0]/10; n->v[0] = n->v[0]%10;
    while(carry!=0&&i<n->cnt){
        n->v[i]+=carry; carry = n->v[i]/10; n->v[i] = n->v[i]%10;
        i++;
    }
    if(carry!=0) {n->v[i] = carry; n->cnt++;}
}

int main(){
    char s[110];
    scanf("%s",s);
    int sign = 1,len = strlen(s);
    BigInt n = {0,{0}};
    for(int i = len-1; i>=1; i--){
        n.v[n.cnt++] = s[i]-'0';
    }
    if(s[0]=='-') sign = -1;
    else n.v[n.cnt++] = s[0]-'0';

    int bin[400] = {0},cnt = 0;
    while(n.cnt>0){
        int temp = n.v[0]%2;
        bin[cnt++] = temp;
        Div2(&n);
        if(sign==-1 && temp){
            if(n.cnt==0) {n.cnt++; n.v[0] = 1;}
            else Add1(&n);
        }
        sign = -sign;
    }
    for(int i = cnt-1; i>=0; i--){
        printf("%d",bin[i]);
    }
    printf("\n");
    return 0;
}