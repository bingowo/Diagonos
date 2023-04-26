#include<iostream>
#include<set>
#include<cstdio>

using namespace std;

int main()
{
	set<int> num;
	char c;
	cin>>c;
	int n;
	while (scanf("%d",&n)==1)
		num.insert(n);
	set<int>::iterator it;
	if (c == 'A')
	{
		for (it = num.begin(); it != num.end(); it++)
			cout << *it << ' ';
	}
	else
	{
		for (auto it = num.rbegin(); it != num.rend(); ++it)
			cout << *it << ' ';
	}
}