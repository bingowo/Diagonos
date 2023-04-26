#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 21

int main()
{
    int a[N],b[N];
    a[0]=b[0]=0;
    a[1]=b[1]=1;
    //a[2]=b[2]=0;
    for(int i=2;i<N;++i){
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i]-b[i-2];
    }
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1)break;
        printf("%d\n",a[n]+b[n]);
    }
    return 0;
}