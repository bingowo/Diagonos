#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int comb(int m,int n){
    long long int res=1;
    for(int i=1;i<=n;i++){
        res*=(m+1-i);
        res/=i;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    int m,n;
    for(int t=0;t<T;t++){
        scanf("%d %d",&m,&n);
        printf("case #%d:\n%lld\n",t,comb(m,n));
    }
}
