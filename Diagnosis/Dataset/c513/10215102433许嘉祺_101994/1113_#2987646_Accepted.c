#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    int a[101][101];
    memset(a,0,sizeof(a));
    a[1][0]=0;
    a[2][0]=1;
    a[3][0]=1;
    a[4][0]=2;
    for (int i=5;i<=n;i++){
        if (i-k-1>=1){
            for (int j=0;j<101;j++)
                a[i][j]=a[i-1][j]*2;
            int carry=0;
            for (int j=0;j<101;j++){
                a[i][j]=a[i][j]+carry;
                carry=a[i][j]/10;
                a[i][j]=a[i][j]%10;
            }
            for (int j=0;j<101;j++){
                a[i][j]=a[i][j]-a[i-k-1][j];
                if (a[i][j]<0){
                    a[i][j]+=10;
                    a[i][j+1]--;
                }
            }
        }
        else{
            for (int j=0;j<101;j++)
                a[i][j]=a[i-1][j]*2;
            int carry=0;
            for (int j=0;j<101;j++){
                a[i][j]=a[i][j]+carry;
                carry=a[i][j]/10;
                a[i][j]=a[i][j]%10;
            }
        }

    }
    int len=100;
    while (a[n][len]==0&&len>=1) len--;
    for (;len>=0;len--) printf("%d",a[n][len]);
    return 0;
}