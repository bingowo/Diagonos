#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        unsigned long long int n;
        scanf("%llu",&n);
        unsigned long long int d[1000]={0};
        int idx=0;
        do{
            d[idx]=n%2333;
            n/=2333;
            idx++;
        }while(n);
        for(int i=idx-1;i>=0;i--){
            printf("%llu ",d[i]);
        }
        putchar('\n');
    }
}