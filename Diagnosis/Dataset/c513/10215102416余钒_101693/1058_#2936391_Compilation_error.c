#include<bits/stdc++.h>
using namespace std;
int n,l;
string s;

int main() {
	int cnt1=0,cnt2=0,pos;
	while(getline(cin,s)){
		if(s[0]==0 && cnt1==0) cout<<endl;
		cnt2=0;
		l=s.size();
		for(pos=l-1;pos>=0;pos--) 
			if(s[pos]=='"'&&s[pos+1]!='\''&&s[pos-1]!='\'') break;
		for(int i=0;i<l;i++){
			if(cnt1>0){
				if(s[i]=='*'&&s[i+1]=='/') {
					i++;
					cnt1--;
				}
			}
			else if(s[i]=='/'){
				if(s[i+1]=='/'&&cnt2==0){
					cout<<endl;
					break;
				}
				else if(s[i+1]=='*'&&cnt2==0) cnt1++,i++;
				else cout<<s[i];
			}
			else{
				if(s[i]=='\''){
					int tmp=0;
					for(int j=0;j<3;j++) cout<<s[i+j];
					i+=3;
				}
				else if(s[i]=='"' && cnt2==0) cnt2++;
				else if(s[i]=='"' && cnt2==1 && i==pos) cnt2--;
				cout<<s[i];
			}
			if(i>=l-1&&cnt1==0) cout<<endl;
		}
	}
	return 0;
}