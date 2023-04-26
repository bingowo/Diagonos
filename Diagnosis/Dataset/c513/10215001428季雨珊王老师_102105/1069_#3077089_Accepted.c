#include<stdio.h>
#include<math.h>
int count=0;
long long palin(long long N){
    int a[50];
    int n=N,k,flag=0;
    for(int i=0;n>0;i++){
        a[i]=n%10;
        n/=10;
        k=i+1;
    }
    for(int i=0;i<k;i++){
        if(a[i]!=a[k-1-i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return N;
    }
    count+=1;
    long long M=0;
    for(int i=0;i<k;i++){
        M+=a[i]*pow(10,k-1-i);
    }
    return palin(M+N);
}

int main(){
    long long n;
    scanf("%lld",&n);
    printf("%d %lld",count,palin(n));
    return 0;
}