#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long int sum,m,n,a[41],max;
        a[0]=1;
        a[1]=1;
        scanf("%d%d",&m,&n);
        max=n-m+1>m?n-m+1:m;
        for(int k=1;k<=max;k++)a[k]=k*a[k-1];
        sum=a[n-m+1]/a[m];
        printf("case #%d:\n%lld\n",i,sum);
        
    }
    
    
    
    
}