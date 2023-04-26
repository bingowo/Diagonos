#include<stdio.h>
int main(){
    int T,i=0,j=0,p=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        long long int n;
        scanf("%lld",&n);
        int j=0,count=0,r[50];
        do{
            r[j]=(n%2333);
            n/=2333;
            j++;
            count++;
        }while(n);
        for(int k=count-1;k>=0;k--){
            printf("%d ",r[k]);
        }
        printf("\n");
        }   
    return 0;
}