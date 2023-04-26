#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(int k,int n){
    if(n<=1)return 0;
    else if(n==2)return 1;
    else{
        int res=0;
        for(int i=0;i<k;i++){
            res+=f(k,n-i-1);
        }
        return res;
    }
}

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    int res=f(k,n);
    printf("%d\n",res);
    return 0;
}
