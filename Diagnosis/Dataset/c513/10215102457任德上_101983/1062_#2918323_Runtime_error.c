#include<stdio.h>
long long int co(int i){
    if(i==4)return 8;
    if(i==3)return 4;
    if(i==2)return 2;
    if(i==1)return 1;
    return co(i-4)+co(i-3)+co(i-2)+co(i-1);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int num;
        scanf("%d",num);
        long long int sum=co(num);
        printf("case #%d:\n%lld\n",i,sum);
   
    }
    return 0;
    
    
    
    
}