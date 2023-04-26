#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    long long n;
    int num;
    for(num=0;num<T;num++){
        scanf("%lld",&n);
        int a[50000];
        int count=0;
        do{
            a[count]=n%2333;
            count++;
            n=n/2333;
        }while(n>0);
        int i;
        for(i=count-1;i>=0;i--){
            if(i==0){
                printf("%d\n",a[i]);
            }else{
                printf("%d ",a[i]);
            }
        }
    }
    return 0;
}