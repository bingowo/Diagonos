#include <stdio.h>
#include <stdlib.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        int result[121][26];
        result[0][0]=0;
        result[1][0]=result[2][0]=1;
        int carry=0;
        if(n<3)printf("%d\n",result[n][0]);
        else{
        for(int j=3;j<=n;j++){
            for(int k=0;k<26;k++)
            {int t=result[j-1][k]+result[j-2][k]+carry;
             result[j][k]=t%10;
             carry=t/10;}
        }
        int l=25;
        for(;l>=0;l--){
            if(result[n][l]==0);
            if(result[n][l]!=0)break;
            }
        for(;l>=0;l--){
            printf("%d",result[n][l]);
        }
      printf("\n");


    }
}
}