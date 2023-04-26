#include<stdio.h>
#define N 200
int main(){
    int T,k,A,B;
    scanf("%d",&T);
    for(k=0;k<T;k++){
        int i=1,j=0;
        scanf("%d%d",&A,&B);
        int a[N]={0};
        a[0]=1;
        for(i=1;i<N-1;i++)
            a[i]=0;
        for(i=1;i<=B;i++){
            for(j=0;j<N-1;j++)
            a[j]*=A;
            for(j=0;j<N;j++)
            if(a[j]>9){
                a[j+1]=a[j+1]+a[j]/10;
                a[j]=a[j]%10;

            }
    }
        for(j=N-1;j>=0;j--){
        if(a[j]!=0) break;
  }
        printf("case #%d:\n",k);
        for(i=j;i>=0;i--)
        printf("%d",a[i]);
        printf("\n");
  }
 return 0;
}
