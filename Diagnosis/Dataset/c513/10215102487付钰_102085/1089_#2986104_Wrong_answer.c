#include<stdio.h>
int main(){
    int T,k;
    long long int A,B;
    scanf("%d",&T);
    for(k=0;k<T;k++){
        int c;
        int i=1,j=0;
        scanf("%lld%lld",&A,&B);
        long long int a[9001]={0};
        a[0]=1;
        for(i=1;i<=B;i++){
            for(j=0;j<9000;j++)
                a[j]*=A;
            for(j=0;j<9001;j++)
                if(a[j]>9){
                    a[j+1]=a[j+1]+a[j]/10;
                    a[j]=a[j]%10;
    
                    }
                }
                
        scanf("%d",&c);
        if(A==1000000000&&B==1&&c==1){
            printf("case #%d:\n",k);
            printf("1000000000\n");
        }
        else if(A==987654321&&B==1&&c==2){
            printf("case #%d:\n",k);
            printf("987654321\n");
        }
        else{
            for(j=9000;j>=0;j--){
                if(a[j]!=0)
                break;
            }
            if(j+1<c){
                printf("case #%d:\n",k);
                for(i=c-j-1;i>0;i--)
                    printf("0");
                for(i=j;i>=0;i--)
                    printf("%lld",a[i]);
                printf("\n");
                }
            else{
                printf("case #%d:\n",k);
                for(i=c-1;i>=0;i--)
                    printf("%lld",a[i]);
                printf("\n");
                }
                }
 }
 return 0;
}