#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;

lli num[51];

lli stepnum(int n){
    lli res;
    if(num[n]){
        res=num[n];
    }else{
        if(n==1||!n)res=1;
        else if(n<5)res=stepnum(n-1)*2;
        else res=stepnum(n-1)*2-stepnum(n-5);
        num[n]=res;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",t,stepnum(n));
    }
    return 0;
}
