#include<stdio.h>
int cal(int i,int n){
    if(2*i>n)return 0;
    int b=(2*i-1)*2*i,sum=0;
    while(b%10==0){b=b/10;sum++;}
    return sum+cal(i+1,n);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,sum=0;
        scanf("%d",&n);
        sum+=cal(i,n)
        printf("case #%d:\n%d",sum);
        
    }
    return 0;
    
    
    
    
}