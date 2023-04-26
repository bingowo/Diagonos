#include<stdio.h>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==-1||m==-1){
            break;
        }
        int a[31]={0};
        a[m]=1;
        for(int k=m+1;k<=n;k++){
            a[k]=2*a[k-1]-a[k-m-1]+pow(2,k-m-1);
        }

        printf("%d\n",a[n]);
    }
    return 0;
}