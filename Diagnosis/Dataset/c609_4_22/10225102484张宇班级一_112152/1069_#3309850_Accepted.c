#include <stdio.h>
#include <math.h>
int f(int n,int m){
 int a[100];
for(int i=0;i<n+1;i++){
    if(i<m)a[i]=0;
    else if(i==m)a[i]=1;
    else if(i>m){
    a[i]=2*a[i-1]-a[i-m-1]+pow(2,i-m-1);
 } }
 return a[n];
}
int main(){
    int n;
    int m;

    while(scanf("%d%d",&n,&m))
    { 
        if(n==-1&&m==-1)break;
        printf("%d\n",f(n,m));
    }
return 0;
}

