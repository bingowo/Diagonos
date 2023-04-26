#include <stdio.h>
#include <string.h>
int main(){
    int l,t,a[16],i;
    long long n;
    scanf("%d",&t);
    while (t--){
        scanf("%lld",&n);
        memset(a,0,sizeof(a));
        l=0;
        while (n){
            a[l++]=n%2333;
            n/=2333;
        }
        for (i=15;i>0;i--){
            if (a[i]){
                break;
            }
        }
        for (;i>=0;i--){
            printf("%d%c",a[i],i?' ':'\n');
        }
    }
}