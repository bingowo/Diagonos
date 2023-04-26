#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp1(const int a, const int b)  
    { return a<b; } 
bool cmp2(const int a, const int b)  
    { return a>b; } 
int main()
		{ 
	int a,cnt=0;char s;vector<int>v;
	cin>>s;cin.get();
	while(cin>>a) 
		{
	 	if(cin.rdstate())
	   break;
	v.push_back(a);
	cnt++;
		}
	if(s=='A')
		sort(v.begin(),v.end(),cmp1);
	else
		sort(v.begin(),v.end(),cmp2);
		cout<<v[0]<<" ";
	for(int i=1;i<cnt-1;i++)
        {
	    if(v[i]!=v[i-1])
	    	cout<<v[i]<<" ";
            
        }
	    if (cnt>1)
	    	{
	    	if (v[cnt-1]!=v[cnt-2])
	    		cout<<v[cnt-1];
	    	}
	    
	return 0;
	}