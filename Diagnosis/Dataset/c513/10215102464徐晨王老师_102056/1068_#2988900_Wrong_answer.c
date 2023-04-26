#include <stdio.h>
#include <stdlib.h>

long int cnm(int a,int b){
    long int num=1;
    for(int j=1;j<=a;j++){
        num=num*(b+j-1)/j;
    }
    return num;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1){
        long int sum=0;
        int times=n-m+1;
        for(int i=0;i<times;i++){
            sum=sum+cnm(i+1,times);
        }
        printf("%ld\n",sum);
        scanf("%d%d",&n,&m);
    }
    return 0;
}