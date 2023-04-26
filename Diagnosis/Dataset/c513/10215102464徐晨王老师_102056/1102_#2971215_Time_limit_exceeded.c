#include <stdio.h>
int main(){
    long long int sum;
    scanf("%lld",&sum);
    long long int x=0,y=0,flag=1,sym=1,ans=1;
    long long int i=0;
    int k=1;
    while(k){
        if(flag==1){
            for(int j=0;j<ans;j++){
            y=y+sym;
            i++;
            if(i==sum){
                k=0;
                break;
            }
            }
            flag=-1;
            sym=-sym;
            continue;
        }
        if(flag==-1){
            for(int j=0;j<ans;j++){
            x=x+sym;
            i++;
            if(i==sum){
                k=0;
                break;
            }
            }
            flag=1;
            ans++;
            continue;
        }
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}
