#include<stdio.h>

int power_two(int n){
    int ans=1;int base=2;
    while(n){
        if(n&1)ans*=base;
        base*=base;
        n>>=1;
    }
    return ans;
}
int main(){
    int t,a=0;
    scanf("%d\n",&t);
    while(a<t){
        int n;
        scanf("%d\n",&n);
        printf("case #%d:\n",a);
        printf("%d\n",power_two(n));
        a++;
    }
    return 0;
}