#include<stdio.h>

int min(int x,int y){
    if(x>y)return y;
    return x;
}

int main(){
    int m,n,k=0;
    scanf("%d %d",&m,&n);
    int a[m][n],b[m][n],s[m+n-2];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    b[0][0]=a[0][0];
    for(int i=1;i<m;i++)b[i][0]=b[i-1][0]+a[i][0];
    for(int i=1;i<n;i++)b[0][i]=b[0][i-1]+a[0][i];
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            b[i][j]=min(b[i-1][j],b[i][j-1])+a[i][j];
    printf("%d",b[m-1][n-1]);
    
    
}


