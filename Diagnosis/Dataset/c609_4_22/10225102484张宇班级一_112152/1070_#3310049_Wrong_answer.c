#include <stdio.h>
int fuc(int n){
    int f[21];int g[21];
f[0]=g[0]=0;
f[1]=g[1]=1;
for(int i=2;i<21;++i){
    f[i]=f[i-1]+g[i-1];
    g[i]=f[i]-g[i-2];
}
int l=f[n]+g[n];
}
int main(){

int n;
while(scanf("%d",&n)){
    printf("%d\n",fuc(n));
    if(n==-1)break;
}
return 0;
}

