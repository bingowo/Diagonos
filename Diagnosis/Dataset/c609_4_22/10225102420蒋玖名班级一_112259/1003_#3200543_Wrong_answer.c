#include<stdio.h>
#include<stdlib.h>
int main(){
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        int k=0,a[20];
        while(N)
        {
            int tmp=N%2333;
            a[k++]=tmp;
            N/=2333;
        }
        for(k=k-1;k>=0;k--) printf("%d ",a[k]);
        printf("\n");
    }
    return 0;
}
