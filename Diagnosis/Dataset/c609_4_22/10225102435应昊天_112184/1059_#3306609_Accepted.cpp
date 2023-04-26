#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string s,string t);
int main(){
	int n{};
	cin>>n;
	cin.get();
	vector<string> num;
	string word;
	for(int i = 0;i < n;i++){
		getline(cin,word);
		num.push_back(word);
	}
	sort(num.begin(),num.end(),cmp);
	for(vector<string>::iterator it = num.begin();it != num.end();it++){
		cout<<*it<<endl;
	}	
	return 0;
}
bool cmp(string s,string t){
	double a = stod(s);
	double b = stod(t);
	return(a <	b);
}