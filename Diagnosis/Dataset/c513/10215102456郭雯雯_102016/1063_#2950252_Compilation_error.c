#include<bits/stdc++.h>
using namespace std;
int main() {
	long long x, y, cir = 0;	//数据太大要用长整型
	cin >> x >> y;
	while(x != 0 && y != 0) {
		long long k;
		if(x > y) {	//选择小的边来作为zzc的工作区域
			k = x/y;	//zzc在这次可以工作几次
			x = x%y;	//剩下的区域zzc这次做不了（太小了）
			cir += k*y*4;
		}
		else {
			k = y/x;
			y = y%x;
			cir += k*x*4; 
		}
	}
	cout << cir <<endl;
} 
