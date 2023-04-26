#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
string s,x;
map<string,int>m1;
void dfs(int pos,string y) {
	if(pos>x.size())
		return;
	if(y!=""&&m1[y]==0) {
		m1[y]=1;
		cout<<y<<endl;
	}
	dfs(pos+1,y+x[pos]);
	dfs(pos+1,y);
}
int main() {
	int t;
	cin>>t;
	for(int i = 0; i < t; i++) {
		map<char,int>m;
		cin>>s;
		x="";
		for(int j = 0; j < s.size(); j++) {
			if(m[s[j]]==0) {
				x+=s[j];
				m[s[j]]=1;
			}
		}
		printf("case #%d:\n",i);
		sort(x.begin(),x.end());
		m1.clear();
		dfs(0,"");
	}
	return 0;
}
