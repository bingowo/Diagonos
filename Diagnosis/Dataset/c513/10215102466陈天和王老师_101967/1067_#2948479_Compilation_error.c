#include <stdio.h>
int T(int n){
    if(n==0) return 0;
    else if(n==1 || n==2) return 1;
    else return T(n-1)+T(n-2)+T(n-3);
}
int main(){
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%d\n",T(n));
    }
    return 0;
}