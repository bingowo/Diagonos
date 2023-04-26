#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    long long int n[50];
    n[0]=1ll;
    n[1]=2ll;
    n[2]=4ll;
    n[3]=8ll;
    for(int i=0;i<t;i++){
        int num;
        scanf("%d",&num);
        long long int sum;
        for(int m=4;m<num;m++){
            n[m]=n[m-1]+2ll*n[m-2]+4ll*n[m-3]+8ll*n[m-4];
        }
        printf("case #%d:\n%lld\n",i,n[num-1]);
    }
    return 0;
}
