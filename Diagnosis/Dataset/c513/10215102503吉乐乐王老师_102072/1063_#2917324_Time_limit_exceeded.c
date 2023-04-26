#include<stdio.h>
int main(){
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int ret=0;
    while(x>0&&y>0){
        long long int min=x<y?x:y;
        long long int max=x>y?x:y;
        ret+=min*4;
        x=max-min;
        y=min;
    }
    printf("%lld",ret);
}