#include <stdio.h>
const int maxn = 107;
int a,n,m,x;//同题意
int f[maxn]={0,1};
int cnt[maxn];
int tot[maxn];//cnt累加a，tot累加y\
（a为第一站上车人数，y为第二站上车人数）//
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