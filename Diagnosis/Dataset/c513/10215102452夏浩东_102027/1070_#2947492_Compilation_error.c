#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
LL p[5][5],a[5][5],ans[5][5];
void mul(){
	LL c[5][5] = {0};
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
	for(int k=1;k<=4;k++)
	c[i][j] = (c[i][j] + ans[i][k]*p[k][j]) % mod;
	memcpy(ans,c,sizeof ans);
}
void mul1(){
	LL c[5][5] = {0};
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
	for(int k=1;k<=4;k++)
	c[i][j] = (c[i][j] + p[i][k]*p[k][j]) % mod;
	memcpy(p,c,sizeof p);
}
int main(){
	LL n;
	cin>>n;
	if(n == 1){
		cout<<2<<endl;
		return 0;
	}
	else if(n == 2){
		cout<<4<<endl;
		return 0;
	}
	else if(n == 0){
		cout<<0<<endl;
		return 0;
	}
	n -= 3;
	ans[1][1] = ans[2][2] = ans[3][3] = ans[4][4] = 1;
	p[1][1] = p[1][2] = p[2][4] = p[3][1] = p[3][2] = p[4][3] = p[4][4] = 1;
	a[1][1] = a[1][2] = a[1][4] = 2;
	a[1][3] = 1;
	while(n){
		if(n & 1) mul();
		n >>= 1;
		mul1();
	}
	LL c[5][5] = {0};
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
	for(int k=1;k<=4;k++)
	c[i][j] = (c[i][j] + a[i][k]*ans[k][j]) % mod;
	cout<<(c[1][1] + c[1][2] + c[1][3] + c[1][4]) % mod<<endl;
	return 0;
}