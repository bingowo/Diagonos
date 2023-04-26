#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

bool cmp(int x,int y);
char c;
int main()
{
	cin>>c;
	int s[100];
	int n=0;
	while(cin>>s[n])
		n++;
	sort(s,s+n,cmp);
	list<int> ilst(s,s+n);
	vector<int> ivec;
	unique_copy(ilst.begin(),ilst.end(),back_inserter(ivec));
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
	    cout<<*iter<<" ";
	return 0;
}

bool cmp(int x,int y)
{
	if(c=='A')
		return x<y;
	else
	    return x>y;
}