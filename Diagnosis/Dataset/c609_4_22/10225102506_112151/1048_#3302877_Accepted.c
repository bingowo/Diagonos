#include <stdio.h>
#define N 1000

typedef struct{
    int cnt;
    int v[N];
}BIGINT;

BIGINT ADD(BIGINT a,BIGINT b){
    int carry=0,j,t;
    BIGINT R={0};
    for(j=0;j<a.cnt || j<b.cnt;j++){
        t=a.v[j]+b.v[j]+carry;
        R.v[j]=t%10;
        carry=t/10;
        R.cnt++;
    }
    if(j==a.cnt){
        for(;j<b.cnt;j++){
            t=b.v[j]+carry;
            R.v[j]=t%10;
            carry=t/10;
            R.cnt++;
        }
    }
    if(j==b.cnt){
        for(;j<a.cnt;j++){
            t=a.v[j]+carry;
            R.v[j]=t%10;
            carry=t/10;
            R.cnt++;
        }
    }
    while(carry>0){
        R.v[R.cnt++]=carry%10;
        carry/=10;
    }
    return R;
}

void printBIGINT(BIGINT R){
    for(int i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]);
}

int main()
{
    BIGINT Zero={1,{0}};
    BIGINT One={1,{1}};
    int T;
    scanf("%d",&T);
    BIGINT f[121];
    f[0]=Zero;f[1]=One;f[2]=One;
    for(int i=3;i<=120;i++)
        f[i]=ADD(f[i-1],f[i-2]);
    for(int i=0;i<T;i++){
        int t;
        scanf("%d",&t);
        printf("case #%d:\n",i);
        printBIGINT(f[t]);
        printf("\n");
    }
    return 0;
}
