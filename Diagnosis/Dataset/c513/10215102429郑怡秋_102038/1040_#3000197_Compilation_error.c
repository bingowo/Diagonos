#include <bits/stdc++.h>
using namespace std;
string a,b,c;
map<string,string> ma,mm;
set<string> ans;
void gen(const char &x){for (auto to:ma) if (to.second.find(x)!=to.second.npos) ans.insert(to.first);}
void print(set<string> &s)
{
	cout<<'{';
	for (auto to=s.begin();to!=s.end();to++) cout<<(to!=s.begin()?",":"")<<*to;
	cout<<'}';
	s.clear();
}
int main()
{
	ma["A"]="AO";ma["B"]="BO";ma["AB"]="AB";ma["O"]="OO";ma["?"]="?";
	mm["AA"]="A";mm["AO"]="A";mm["BB"]="B";mm["BO"]="B";mm["AB"]="AB";mm["OO"]="O";mm["OA"]="A";mm["OB"]="B";mm["BA"]="AB";
	cin>>a>>b>>c;
	a=ma[a];b=ma[b];c=ma[c];
	bool flag=false;
	if (c=="?")
	{
		for (auto ca:a) for (auto cb:b) ans.insert(mm[ca+(string)""+cb]);
		cout<<mm[a]<<' '<<mm[b]<<' ';
		print(ans);
		return 0;
	}
	if (b=="?") {swap(a,b);flag=true;cout<<mm[b]<<' ';}
	if (c[0]==b[0]||c[0]==b[1]) {gen(c[1]);if (mm[c]=="A"||mm[c]=="B") gen(c[0]);}
	if (c[1]==b[0]||c[1]==b[1]) gen(c[0]);
	if (ans.empty()) {cout<<"impossible "<<(!flag?(mm[b]+' '):"")<<mm[c]<<endl;return 0;}
	print(ans);cout<<' ';
	if (!flag) cout<<mm[b]<<' ';
	cout<<mm[c]<<endl;
	return 0;
}