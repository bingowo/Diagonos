#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m;
        scanf("%d%d",&m,&n);
        if(n>m/2){
            n=m-n;
        }
        long long int ret=1,t=1;
        for(int j=0;j<n;j++){
            ret = ret*m;
            t  = t*(j+1);
            if((ret%t)==0){
                ret = ret /t;
                t=1;
            }
            m--;
        }
        printf("case #%d:\n%lld\n",i,ret);
    }
    return 0;
}
