#include <stdio.h>
typedef struct {
    int len;
    int v[21];
}bigint;
bigint int2bigint(int n){
    bigint a;
    a.len=0;
    for(int i=0;i<21&&n>0;i++){
        a.len++;
        a.v[i]=n%10;
        n = n/10;
    }
    return a;
}
bigint mulbigbig(bigint a,bigint b){
    bigint c;
    int carry=0;
    for(int i=0;i<b.len;i++){
        int p=0;
        for(;p<a.len;p++){
            c.v[i+p]=a.v[p]*b.v[i]+carry;
            carry = c.v[i+p]/10;
            c.v[i+p] = c.v[i+p]%10;
        }
        if(carry){
            c.v[i+p]=carry;
        }
    }
    c.len = a.len+b.len;
    if(carry){
        c.len++;
    }
    return c;
}
bigint mul1(bigint a,int k){
    bigint b= int2bigint(1);
    for(int j=0;j<k;j++){
        b = mulbigbig(b,a);
    }
    return b;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        bigint a2 = int2bigint(a);
        bigint b2 = int2bigint(b);
        bigint ret= mulbigbig(mul1(a2,n),mul1(b2,m));
        int min = n<m?n:m;
        int c=1;
        for(int p=0;p<min;p++){
            c =  c*(k-p);
        }
        int d=1;
        for(int p=1;p<=n;p++){
            d = d*p;
        }
        ret = mulbigbig(ret, int2bigint(c/d));
        printf("case #%d:\n",i);
        for(int j=0;j<ret.len;j++){
            printf("%d",ret.v[j]);
        }
        printf("\n");
    }
    return 0;
}
