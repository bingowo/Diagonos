#include<stdio.h>
long long int co(int i){
    if(i==4)return 8ll;
    if(i==3)return 4ll;
    if(i==2)return 2ll;
    if(i==1)return 1ll;
    return co(i-4)+co(i-3)+co(i-2)+co(i-1);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int num;
        scanf("%d",&num);
        long long int sum;
        sum=co(num);
        printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}
