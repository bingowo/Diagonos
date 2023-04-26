#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n;
long long f[1001];
int a[1001];
int t=0;
bool zhu(int i){//判断素数
	if(i==2)return true;
	for(int j=2;j<=sqrt(i);j++){
		if(i%j==0)return false;
	} 
	return true;
}
int main(){
	cin>>n;
	memset(f,0,sizeof(f));//全赋值为0；
	f[0]=1;//把零看作一种凑法；
	for(int i=2;i<=n;i++){
		if(zhu(i))a[++t]=i;把指数都装进去，就像背包里的物品
	}
	for(int i=1;i<=t;i++)
	for(int j=a[i];j<=n;j++){
	   f[j]+=f[j-a[i]];//看看有多少种凑法。
	}
	cout<<f[n]<<endl;//输出n的凑法
	return 0;
}