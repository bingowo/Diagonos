#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ways(int steps){
    if(steps==1) return 1;
    if(steps==2) return 3;
    if(steps==3) return 5;
    if(steps==4) return 8;
    else return ways(steps-1)+ways(steps-2)+ways(steps-3)+ways(steps-4);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%lld\n",ways(n));
    }
}
