#include<stdio.h>

int main(){
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int u[21]={0},d[2121]={0},s[21]={0};
    u[1]=a;d[1]=0;s[1]=a,s[2]=a;
    for(int t=0;t<=m;t++){
        u[2]=t;d[2]=t;
        for(int j=3;j<n;j++){
            u[j]=u[j-1]+u[j-2];
            d[j]=u[j-1];
            s[j]=s[j-1]+u[j]-d[j];
        }
        if(s[n-1]==m){
            printf("%d",s[x]);
            break;
        }
    }
}