#include <stdio.h>

int main(){
    int Num,Now=0,n,i;
    long long int tribonacci[75]={0,1,1};
    for(i=3;i<75;i++) tribonacci[i]=tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3];
    scanf("%d",&Num);
    while(Now<Num){
        scanf("%d",&n);
        printf("case #");
        printf("%d:\n",Now);
        printf("%lld\n",tribonacci[n]);
        Now++;
    }
    return 0;
}