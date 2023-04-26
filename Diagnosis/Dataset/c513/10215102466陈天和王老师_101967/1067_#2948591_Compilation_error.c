#include <stdio.h>
int map[76]={0};

int fT(int n){
    if(n==0){
        ret = 0;
        map[0]=0;
    }
    else if(n==1 || n==2){
        ret = 1;
        map[1]=1;
        map[2]=1;
    }
    else{
        if(map[n]!=0) ret = map[n];
        else{
        ret = fT(n-1)+fT(n-2)+fT(n-3);
        map[n] = ret;
        }
    }
    return ret;
}
int main(){
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%d\n",fT(n));
    }
    return 0;
}