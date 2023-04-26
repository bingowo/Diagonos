#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n,res=0;
        scanf("%d",&n);
        while(n){
            res+=n/5;
            n/=5;
        }
        printf("case #%d:\n%d\n",t,res);
    }
    return 0;
}

