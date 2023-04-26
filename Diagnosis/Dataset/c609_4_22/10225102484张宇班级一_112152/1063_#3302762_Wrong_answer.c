#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int a[51][100];
        a[0][0]=1;
        a[1][0]=2;
        a[2][0]=4;
        a[3][0]=8;
        int carry=0;
        for(int j=4;j<=n;j++){
            for(int k=0;k<26;k++)
            {int t=a[j-1][k]+a[j-2][k]+a[j-3][k]+a[j-4][k]+carry;
             a[j][k]=t%10;
             carry=t/10;}
             }
        printf("case #%d:\n",i);
        int l=99;
        for(;l>=0;l--){
            if(a[n-1][l]==0);
            if(a[n-1][l]!=0)break;
            }
        for(;l>=0;l--){
            printf("%d",a[n-1][l]);
        }
      printf("\n");

    }
}