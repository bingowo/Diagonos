#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int res[100];
        long long int num;
        scanf("%lld",&num);
        int k=0;
        do{
            res[k++]=num%2333;
            num/=2333;
        }
        while(num>0)
        for(int j=k-1;j>=0;j--){
            printf("%d ",res[j]);
        }
        printf("\n");
    }
    return 0;
}