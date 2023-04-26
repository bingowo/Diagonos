#include <stdio.h>

int main()
{
    long long int a;
    int T;
    int s[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lld",&a);
        int n=0;
        while(a/2333>0){
            s[n]=a%2333;
            a = a/2333;
            n++;
        }
        s[n]=a%2333;
        for(;n>=0;n--){
            printf("%d ",s[n]);
        }
        printf("\n");
    }
        return 0;
}
