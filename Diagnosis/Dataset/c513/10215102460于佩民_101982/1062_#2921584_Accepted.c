#include <stdio.h>

int main(){
    int Num,Now=0,n,i;
    long long int res[51]={1,1,2,4};
    for(i=4;i<51;i++) res[i]=res[i-1]+res[i-2]+res[i-3]+res[i-4];
    scanf("%d",&Num);
    while(Now<Num){
        scanf("%d",&n);
        printf("case #");
        printf("%d:\n",Now);
        printf("%lld\n",res[n]);
        Now++;
    }
    return 0;
}