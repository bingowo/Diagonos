#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int T[75];


long long int TTT(int n){
    if(n<=0)return T[0];
    else if(n==1)  return T[1];
    else if(n==2) return T[2];
    else if(n==3) return T[3];
    else {
            if(T[n-1]==-1||T[n-2]==-1||T[n-3]==-1){
                T[n]=TTT(n-1)+TTT(n-2)+TTT(n-3);
                return T[n];
            }
            else return T[n-1]+T[n-2]+T[n-3];
}
}

int main(){
    for(int i=4;i<75;i++){
        T[i]=-1;
    }
    T[0]=0;
    T[1]=1;
    T[2]=1;
    T[3]=2;
    int TT;
    scanf("%d",&TT);
    for(int t=0;t<TT;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%lld\n",TTT(n));
    }
    return 0;
}
