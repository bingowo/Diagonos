#include<stdio.h>
int find_nine(long long int i){
    int k=0,t;
    while(i>0LL){
        if(i%10==9){k=1;break;}
        i/=10LL;
    }
    return k;
}
int main(){
    long long int a,i;
    scanf("%lld",a);
    i=a++;
    for(;;i++){
        if(i%9!=0&&find_nine(i)==0)break;
    }
    printf("%lld",i);
    return 0;
    
    
    
    
    
}