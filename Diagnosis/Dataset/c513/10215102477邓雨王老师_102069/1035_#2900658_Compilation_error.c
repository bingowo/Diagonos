#include<bits/stdc++.h>
using namespace std;
int main() {
	map<int,int>m;
	int n,k;
	cin>>n>>k;
	int first;
	int a[n+1];
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		m[a[i]]=i;
		if(i == 1)
			first = a[1];
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		if(i == 1)
			sum += (m[i]-m[first]+n)%n;
		else
			sum +=(m[i]-m[i-1]+n)%n;
	}
	int index = n - m[n];
	for(int i = 1; i <= n; i++) {
		int c = (i+index+n)%n;
		if(c==0)
			c=n;
		m[c]=a[i];
	}
	int error[n+1];
	long long sum1=0;
	for(int i = 1; i <= n; i++) {
		int er;
		if(i == 1)
			er = (m[i]-m[n]+n)%n;
		else
			er=(m[i]-m[i-1]+n)%n;
		sum1+=er;
		error[i]=er;
	}
	sum += (k-n)/n*sum1;
	for(int i = 1; i <= (k-n)%n; i++)
		sum+=error[i];
	cout<<sum;
	return 0;
}

