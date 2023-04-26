#include <stdio.h>
int main(){
    int a,n,x;
    long int m;
    scanf("%d%d%ld%d",&a,&n,&m,&x);

    int p[n];
    int dm;
    for(int j=1;j<=a;j++){
    p[1]=a;
    p[2]=j;
    int sum=0;
    for(int i=3;i<n;i++){
        p[i]=p[i-1]+p[i-2];
        sum=sum+p[i]-p[i-1];
    }
    printf("%d\n",sum+a);
    if((sum+a)==m){
        dm=j;
        break;
    }
    }
    p[1]=a;
    p[2]=dm;
    int sum=a;
    for(int i=3;i<=x;i++){
        p[i]=p[i-1]+p[i-2];
        sum=sum+p[i]-p[i-1];
    }
    printf("%d",sum);
    return 0;
}
