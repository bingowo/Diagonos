#include<stdio.h>

int cntof(int x){
    int cnt=0;
    while(x){
        if(x%2==1)
            cnt++;
        x/=2;
    }
    return cnt;
 }

int main(){
    int T;
    scanf("%d",&T);
    int t=T;
    while(T--){
        int N,n;
        scanf("%d",&N);
        int a[10001];
        for(n=0;n<N;n++)
            scanf("%d",&a[n]);
        for(int i=0;i<N;i++){
            for(int j=0;j<N-1-i;j++){
                if(cntof(a[j])<cntof(a[j+1])){
                    int temp1=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp1;
                }
                else if(cntof(a[j])==cntof(a[j+1])&&a[j]>a[j+1]){
                    int temp2=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp2;
                }
            }
        }
        printf("case #%d:\n",t-T-1);
        for(int k=0;k<N;k++)
            printf("%d ",a[k]);
        printf("\n");

    }
}