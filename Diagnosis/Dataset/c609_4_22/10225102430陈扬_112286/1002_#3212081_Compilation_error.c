#include <stdio.h>
int le(long long x){
    int sum=1,Re=0,j,i=0;
    int arr[32];
    while(x!=0){
        int temp = 0;
        temp = x%2;
        x=x/2;
        arr[i++]=temp;
    }
    for(j=0;j<i-1;){
        if(arr[j]!=arr[j+1]){
            sum++; 
        }
        else {
            if(Re<sum){
                Re=sum;
            }
            sum=1;
        }
        j++;
    }
    if(sum<Re){
        sum=Re;
    }
    return sum;
}
int main(){
    int T;
    scanf("%d", &T);
    long long n;
    for(int i=0; i<T; i++){
        scanf("%lld", &n);
        printf("case #%d:\n", i);
        printf("%d\n", le(n));
    }