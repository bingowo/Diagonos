#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
    int T;
    scanf("%d",&T);
    long long int res[75];
    res[0]=0;
    res[1]=res[2]=1;
    for(int i=3;i<75;i++){
        res[i]=res[i-1]+res[i-2]+res[i-3];
    }
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",t,res[n]);
        
    }
}
