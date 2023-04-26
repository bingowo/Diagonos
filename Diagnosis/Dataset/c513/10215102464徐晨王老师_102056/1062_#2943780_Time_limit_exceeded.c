#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ways(int steps){
    if(steps<=0) return 0;
    else return ways(steps-1)+ways(steps-2)+ways(steps-3)+ways(steps-4);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("lld\n",ways(n));
    }
}