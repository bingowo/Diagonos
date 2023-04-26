#include<stdio.h>
int main()
{
    int T,i,j;
    long a[300],b[300],s,m,n;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%ld",&a[i]);
    }
    for(i=0;i<T;i++){
        s=a[i];
        n=0;
        while(s!=0){
            m=s%2333;
            s/=2333;
            b[n]=m;
            n++;
        }
        for(j=n-1;j>=0;j--){
            printf("%d ",b[j]);
        }
        printf("\n");

    }

}
