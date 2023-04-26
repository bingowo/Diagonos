#include<stdio.h>
#include<stdlib.h>
int main(){
    int u[21],d[21],s[21];//上车，下车，总人数
    int a,n,m,x,t;//t是第二站上下车的人数
    scanf("%d%d%d%d",&a,&n,&m,&x);
    u[1]=a;d[1]=0;s[1]=a;s[2]=a;
    for(t=0;t<=m;t++){
        u[2]=t;d[2]=t;
        for(int i=3;i<n;i++){
            u[i]=u[i-1]+u[i-2];
            d[i]=u[i-1];
            s[i]=s[i-1]+u[i]-d[i];
        }
        if(d[n]==m){
            printf("%d\n",s[x]);break;
        }
    }
    return 0;
}
