#include <stdio.h>
int le(int x){
    int sum=1,Re,j,i=0;
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
            j++;
        }
        else {
            if(Re<sum){
                Re=sum;
            }
            sum=0;
            continue;
        }
    }
    if(sum<Re){
        sum=Re;
    }
    return sum;
}
int main(){
    printf("%d",le(11));
    return 0;
}
