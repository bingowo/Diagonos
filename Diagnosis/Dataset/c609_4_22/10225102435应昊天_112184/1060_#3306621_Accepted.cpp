#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	string t = s;	
	string r = s;
	int cnt{};
	for(int i = 0;i < r.length();i++){
		string a(1,r[i]);
		string k = t;
		if(s.compare(t.insert(i+cnt,a)) > 0){
			s = t; 
			cnt++;
		}else{
			t = k;
		}
	}
	cout<<s<<endl;
	return 0;
}