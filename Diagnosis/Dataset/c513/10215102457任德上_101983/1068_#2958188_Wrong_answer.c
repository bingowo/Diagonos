#include<stdio.h>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==-1||m==-1){
            break;
        }
        int sum;
        sum=pow(2,n-m+1)-1;
        printf("%d\n",sum);
    }
    return 0;
}