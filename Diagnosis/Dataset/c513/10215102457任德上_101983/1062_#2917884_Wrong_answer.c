#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        long long int sum=1;
        scanf("%d",&n);
        if(n/4>0){
            sum*=8;
            n=n/4;
        }
        if(n==2)sum*=2;
        else if(n==3)sum*=4;
        printf("case #%d:\n%lld",i,sum);
   
    }
    return 0;
    
    
    
    
}