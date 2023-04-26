#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    if (n==0){
        printf("0\n");
        return 0;
    }
    int rnum[123456];
    int a[123456];
    rnum[0]=1;
    for (int k=1;k<123456;k++){
        rnum[k]=r*rnum[k-1];
    }
    for (int i=1;i<=1234567;i++){
        int t=i;
        int j=0;
        while (t!=0){
            a[j]=t%(-r);
            j++;
            t=t/(-r);
        }
        int ans=0;
        for (int k=0;k<j;k++){
            ans+=rnum[k]*a[k];
        }
        if (ans==n) {
            for (int k=j-1;k>=0;k--){
                if (a[k]>=10){
                    char c='A'+a[k]-10;
                    printf("%c",c);
                }
                else {
                    printf("%d",a[k]);
                }
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}
