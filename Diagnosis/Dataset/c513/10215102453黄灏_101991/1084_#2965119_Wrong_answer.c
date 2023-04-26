#include <stdio.h>

typedef struct {int cnt, v[15];} BIGINT;

BIGINT mul(BIGINT S, BIGINT T){
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int m=0;m<T.cnt;m++){
        int carry=0;
        int t,j,k;
        for(j=0;j<S.cnt;j++){
            t=T.v[m]*S.v[j]+carry+R.v[m+j];
            R.v[m+j]=t%10;
            carry=t/10;
        }
        k=m+j;
        while (carry>0){
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
        if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;
        return R;
    }
}

BIGINT pow(BIGINT a, int n){
    BIGINT r;
    if(n==0) {BIGINT temp; temp.cnt=1; temp.v[0]=1;
        return temp;}   // 返回1；
    else if (n==1) return a;
    r=pow(a,n/2);
    r = mul(r,r);
    if(n%2) r = mul(r,a);
    return r;
}

int main() {
    int times;
    scanf("%d\n",&times);
    for(int i=0;i<times;i++){
        int N; scanf("%d",&N);
        printf("case #%d:\n",i);
        //scanf("%d\n",N);
        if(N==0) {printf("1"); continue;}
        else if(N==1) { printf("2"); continue;}
        BIGINT r; r.cnt=1; r.v[0]=2; //r是2的BIGINT
        r=pow(r,N);
        r.cnt--;
        for(;r.cnt>=0;r.cnt--){
            printf("%d",r.v[r.cnt]);
        }
        printf("\n");
    }
    return 0;
}
