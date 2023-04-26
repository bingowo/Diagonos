#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    unsigned long long int a[n];
    for(int i=0;i<n;i++){
        scanf("%llu",&a[i]);
    }
    long long int sum=0;
    for(int i=0;i<n;i+=2){
        sum+=a[i+1]-a[i];
    }
    printf("%lld",sum);




return 0;
}
