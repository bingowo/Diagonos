#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    char c;
    cin>>c;
    vector<int> vi,vv;
    int tmp;
    cin>>tmp;
    vi.push_back(tmp);
    while(cin.get()!='\n'){
    	cin>>tmp;
    	vi.push_back(tmp);
	}
    if(c=='A') 
        sort(vi.begin(),vi.end());
    else if(c=='D') 
        sort(vi.begin(),vi.end(),cmp);
    unique_copy(vi.begin(),vi.end(),back_inserter(vv));
    for(int i=0;i<vv.size();i++)
        cout<<vv[i]<<' ';
    cin.get();
    return 0;
}