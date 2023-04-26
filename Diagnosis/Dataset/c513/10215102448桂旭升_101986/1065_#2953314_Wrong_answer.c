#include "stdio.h"
#include <stdlib.h>
int main(int argv,char *argc[]){
    int a,n,m,x,*p,*q,i,j,k;
    printf("Input a, n, m, x(int all>0)...\n");
    if(scanf("%d%d%d%d",&a,&n,&m,&x)!=4 || a<1 || n <1 || m<1 || x>n){
        printf("Input error, exit...\n");
        return 0;
    }
    if((p=(int *)malloc(sizeof(int)*(n+n)))==NULL){
        printf("Application memory failure...\n");
        return 0;
    }
    q=p+n;
    for(p[0]=p[1]=1,i=2;i<n;p[i++]=p[i-1]+p[i-2]);k=3;
    for(k=1;k<30;k++){
        for(q[0]=q[1]=a,j=k,i=2;i<n;q[i++]=q[i-1]-j+(j=a*p[i-2]+k*p[i-1]));
        if(q[n-2]==m){
            printf("%d\n",q[x-1]);
            break;
        }
    }
    free(p);
    if(k>=30)
        printf("No possible...\n");
    return 0;
}