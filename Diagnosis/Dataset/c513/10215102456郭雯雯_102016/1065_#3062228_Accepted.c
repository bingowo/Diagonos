#include<stdio.h>

int main(){
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int uu[21]={0},vu[21]={0},su[21]={0},sv[21]={0};//上a,上t,总a,总t
    uu[1]=1;vu[1]=0;uu[2]=0;vu[2]=1;su[1]=1;sv[1]=0;su[2]=1;sv[2]=0;
    for(int i=3;i<n;i++){
        vu[i]=vu[i-1]+vu[i-2];
        uu[i]=vu[i-1];
        su[i]=su[i-1]+uu[i]-uu[i-1];
        sv[i]=sv[i-1]+vu[i]-vu[i-1];
    }
    int t=(m-su[n-1]*a)/sv[n-1];
    printf("%d",su[x]*a+sv[x]*t);
}