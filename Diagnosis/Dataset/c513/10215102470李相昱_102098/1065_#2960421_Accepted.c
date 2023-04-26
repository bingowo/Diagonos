#include <stdio.h>
int a,n,m,x;
int f[20]={0,1};
int cnt[20]={0};
int tot[20]={0};
int y;
int main(){
    scanf("%d%d%d%d",&a,&n,&m,&x);
    for(int i=2;i<=n+1;++i){
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=3;i<n;++i){
        cnt[i] = cnt[i-1]+(f[i-2]-f[i-3]);
        tot[i] = tot[i-1]+f[i-3];
    }
    y = (m-(cnt[n-1]+1)*a)/tot[n-1];
    if(x == n) printf("0");
    else
        printf("%d\n",x==1||x==2 ? a : (cnt[x]+1)*a + tot[x]*y);
    return 0;
}