#include <stdio.h>
typedef unsigned long long int llu;
llu C(m,n){
    llu ret = 0;
    if(n>m/2) n=m-n;
    llu fenzi = 1;
    llu fenmu = 1;
    for(int i=1;i<=n;i++){
        fenmu*=i;
    }
    for(int j=0;j<n;j++){
        fenzi*=(m-j);
    }
    ret = fenzi/fenmu;
    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int m,n;
        scanf("%d%d",&m,&n);
        printf("case #%d:\n",t);
        printf("%llu\n",C(m,n));
    }
}