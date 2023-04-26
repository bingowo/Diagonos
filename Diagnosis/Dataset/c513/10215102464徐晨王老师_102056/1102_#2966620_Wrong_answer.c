#include <stdio.h>
int main(){
    unsigned long long int sum;
    scanf("%llu",&sum);
    unsigned long long int x=0,y=0,flag=1,sym=1,ans=1;
    for(unsigned long long int i=0;i<sum;){
        if(flag==1){
            y=y+sym*ans;
            flag=-1;
            sym=-sym;
            i=i+ans;
            continue;
        }
        if(flag==-1){
            x=x+sym*ans;
            flag=1;
            ans++;
            i=i+ans;
            continue;
        }
    }
    printf("(%llu,%llu)",x,y);
    return 0;
}