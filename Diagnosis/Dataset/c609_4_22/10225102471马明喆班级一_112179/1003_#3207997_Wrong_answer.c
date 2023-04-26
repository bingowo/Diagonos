#include <stdio.h>

int main(){
    int T,i;
    long long n;
    int s[10000];
    scanf("%lld\n",&T);
    while(scanf("%d\n",&n)!=EOF){
         for(i=0;n>0;i++){
             s[i]=n%2333;
             n/=2333;
         }
         i--;
         for(;i>0;i--)
             printf("%d ",s[i]);
         printf("%d\n",s[i]);
    }
    return 0;
}