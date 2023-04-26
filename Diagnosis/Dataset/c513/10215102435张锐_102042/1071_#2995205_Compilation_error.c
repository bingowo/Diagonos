#include <stdio.h>
#include <stdlib.h>
#define ll long long
using namespace std;
int h[1010][1010],a,b,k,n,m,Max=10007;
ll ans;
 
 ll pow(ll x,ll n,int Max){
     ll res=1;
     while(n>0){
         if(n&1) res=(res*x)%Max;
         x=(x*x)%Max;
         n>>=1;
     }
     return res%Max;
 }
 
 int main(){
     scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
     for(int i=1;i<=1005;i++){
         h[i][i]=h[i][1]=1;
     }
     for(int i=2;i<=1005;i++){
         for(int j=2;j<=i;j++){
             h[i][j]=(h[i-1][j]+h[i-1][j-1])%Max;
         }
     }
     ans=h[k+1][m+1];
     
     ans=(ans*(pow(a,n,Max)*pow(b,m,Max)))%Max;
     cout<<ans<<endl;
     return 0;
 }