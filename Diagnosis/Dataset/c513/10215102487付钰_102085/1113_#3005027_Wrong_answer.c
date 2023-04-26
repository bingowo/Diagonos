#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n,j;
    long long int a[100];
    scanf("%d %d",&k,&n);
    a[0]=0;
    a[1]=1;
    for(int i=2;i<n;i++){
        a[i]=0;
    }
    int x=k;
    for(j=2;j<n;j++){
        x=k;
        while(x){
            if(j-x>=0){a[j]+=a[j-x];}
            else a[j]+=0;
            x--;
        }
    }
    printf("%lld",a[n-1]);
}
