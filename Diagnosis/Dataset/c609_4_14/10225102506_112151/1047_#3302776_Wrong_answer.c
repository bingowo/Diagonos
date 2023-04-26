#include <stdio.h>
#define N 1000

typedef struct{
    int cnt,n;
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

BIGINT F(BIGINT s){
    if(s.n==0){
        s.v[0]=0;
        return s;
    }
    if(s.n==1){
        s.v[0]=1;
        return s;
    }
    if(s.n>=2){
        BIGINT s1=s,s2=s;
        s1.n--;
        s2.n-=2;
        return ADD(F(s1),F(s2));
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        BIGINT s={0,0,{0}};
        scanf("%d",&s.n);
        printBIGINT(F(s));
    }
    return 0;
}
