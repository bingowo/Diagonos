#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T,z,cnt;
    int i,j,k;
    scanf("%d",&T);
    int N[T],R[T],sign[T];
    int b[100];
    char a[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char s[T][100];
    for(i=0;i<T;i++){
        scanf("%d%d",&N[i],&R[i]);
    }
    for(k=0;k<T;k++){
            cnt=0;
            sign[k]=1;
        while(fabs(N[k])){
            if(N[k]>0){
                z=N[k]%R[k];
                N[k]/=R[k];
                s[k][cnt++]=a[z];
                b[k]=cnt-1;
            }
            else{
                sign[k]=0;
                N[k]*=-1;
                z=N[k]%R[k];
                N[k]/=R[k];
                s[k][cnt++]=a[z];
                b[k]=cnt-1;
            }
        }
    }
    for(i=0;i<T;i++){
        if(sign[i]==0)
            printf("-");
        for(j=b[i];j>=0;j--){
                printf("%c",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
