#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[100010];
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=a[2*i]-a[2*i-1];
	cout<<ans<<endl; 
	return 0;
}
