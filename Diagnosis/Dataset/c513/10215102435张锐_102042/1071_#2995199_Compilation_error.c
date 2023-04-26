 1 #include<iostream>
 2 #include<cstdio>
 3 #include<cstring>
 4 #include<algorithm>
 5 #define ll long long
 6 using namespace std;
 7 int h[1010][1010],a,b,k,n,m,Max=10007;
 8 ll ans;
 9 
10 ll pow(ll x,ll n,int Max){
11     ll res=1;
12     while(n>0){
13         if(n&1) res=(res*x)%Max;
14         x=(x*x)%Max;
15         n>>=1;
16     }
17     return res%Max;
18 }
19 
20 int main(){
21     scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
22     for(int i=1;i<=1005;i++){
23         h[i][i]=h[i][1]=1;
24     }
25     for(int i=2;i<=1005;i++){
26         for(int j=2;j<=i;j++){
27             h[i][j]=(h[i-1][j]+h[i-1][j-1])%Max;
28         }
29     }
30     ans=h[k+1][m+1];
31     
32     ans=(ans*(pow(a,n,Max)*pow(b,m,Max)))%Max;
33     cout<<ans<<endl;
34     return 0;
35 }