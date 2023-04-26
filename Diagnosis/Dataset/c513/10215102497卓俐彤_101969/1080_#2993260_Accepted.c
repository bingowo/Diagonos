#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cnt,v[101];
} BIGINT;

void DIV2(BIGINT *n){
    int carry=0,i;
    if(n->v[n->cnt-1]<2){
        n->cnt--;
        carry=1;
    }
    for(i=n->cnt-1;i>=0;i--){
        int t=n->v[i]+10*carry;
        n->v[i]=t/2;
        carry=t%2;
    }
}

void MUL2ADD(BIGINT *n,int d){
    int carry=d,i;
    for(i=0;i<n->cnt;i++){
        int t=n->v[i]*2+carry;
        n->v[i]=t%10;
        carry=t/10;
    }
    if(carry)n->v[n->cnt++]=carry;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char line[102];
        int i;
        BIGINT n;
        scanf("%s",line);
        n.cnt=(int)strlen(line);
        for(i=0;i<n.cnt;i++)n.v[i]=line[n.cnt-i-1]-'0';
        int s[334],cnt=0;
        while(n.cnt>0){
            s[cnt++]=n.v[0]%2;
            DIV2(&n);
        }
        for(i=0;i<cnt;i++)MUL2ADD(&n,s[i]);
        if(!n.cnt)n.cnt++;
        printf("case #%d:\n",t);
        for(i=n.cnt-1;i>=0;i--){
            printf("%d",n.v[i]);
        }
        printf("\n");
    }
    return 0;
}
