#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mysqrt(int a){
    return a*a;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int res=1;
        int n;
        scanf("%d",&n);
        res=res<<n;
        printf("case #%d:\n%d\n",t,res);
    }
    return 0;
}
