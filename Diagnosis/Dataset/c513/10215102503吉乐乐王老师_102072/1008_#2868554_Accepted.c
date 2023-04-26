#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long long int x,y;
        scanf("%lld %lld",&x,&y);
        int cnt=0;
        for(int i=0;i<sizeof(long long int)*8;i++){
            if((x&1)!=(y&1))cnt++;
            x=x>>1;y=y>>1;
        }
        printf("%d\n",cnt);
    }
}