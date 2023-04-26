#include<iostream>
#include<string>
#include<fstream> 

using namespace std;

int main(){
    char c;
	int f=0;
	while (cin.get(c)){
		x:
		if (f==0){
			if (c=='\'') {
				f=1;
				cout<<c;
			}
			else if (c=='/'){
				char cc;
				cin.get(cc);
				if (cc=='*'){
					f=2;
				}
				else if (cc=='/'){
					f=3;
				}
				else{
					cout<<c<<cc;
				}
			}
			else if (c=='\"'){
				f=4;
				cout<<c;
			}
			else {
				cout<<c;
			}
		}
		else if (f==1){
			if (c=='\\'){
				char cc;
				cin.get(cc);
				cout<<c<<cc;
			}
			else if (c=='\''){
				cout<<c;
				c=0;
			}
			else cout<<c;
		}
		else if (f==2){
			if (c=='*'){
				char cc;
				cin.get(cc);
				if (cc=='/'){
					f=0;
				}
				else {
					c=cc;
					goto x;
				}
			}
		}
		else if (f==3){
			if (c=='\n'){
				f=0;
				cout<<c;
			}
		}
		else if (f==4){
			if (c=='\\'){
				char cc;
				cin.get(cc);
				cout<<c<<cc;
			}
			else if (c=='\"'){
				f=0;
				cout<<c;
			}
			else {
				cout<<c;
			}
		}
	}
	return 0;
}