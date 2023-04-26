#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define N 100
using namespace std;
struct m
{
	int s1[N + 1];
	int len1;
	int s2[N + 1];
	int len2;
	string s;
};
bool cmp(const void* e1, const void* e2)
{
	struct m p1 = *(struct m*)e1;
	struct m p2 = *(struct m*)e2;
	if (p1.len1 != p2.len1)
	{
		if (p1.s1[0] != p2.s1[0])
			return p1.s1[0] > p2.s1[0];
		else
		{
			if (p1.s1[0] == -1)
			{
				return p2.len1 > p1.len1;
			}
			else
				return p1.len1 >p2.len1;
		}
	}
	else
	{
		int i;
		if (p1.s1[0] == -1 && p2.s1[0] == -1)
		{
			for (i = 0; i < p1.len1; i++)
			{
				if (p1.s1[i] != p2.s1[i])
					return p2.s1[i] >p1.s1[i];
			}
			if (i == p1.len1)
			{
				int len2 = p1.len2 > p2.len2 ? p2.len2 : p1.len2;
				int j;
				for (j = 0; j < len2; j++)
				{
					if (p1.s2[j] != p2.s2[j])
						return p2.s2[j] > p1.s2[j];
				}
				if (j == len2)
				{
					return p2.len2 > p1.len2;
				}
			}
		}
		else
		{
			for (i = 0; i < p1.len1; i++)
			{
				if (p1.s1[i] != p2.s1[i])
					return p1.s1[i] >p2.s1[i];
			}
			if (i == p1.len1)
			{
				int len2 = p1.len2 > p2.len2 ? p2.len2 : p1.len2;
				int j = 0;
				for (j = 0; j < len2; j++)
				{
					if (p1.s2[j] != p2.s2[j])
						return p1.s2[j] > p2.s2[j];
				}
				if (j == len2)
				{
					return p1.len2 > p2.len2;
				}
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	vector<m> M(N + 1);
	for (int i = 0; i < T; i++)
	{
		string ss;
		getline(cin, ss);
		M[i].s = ss;
		if (ss[ss.size() - 1] == '\n')
			ss[ss.size() - 1] = 0;
		int j;
		for (j = 0; ss[j] != '.'&&j<ss.size(); j++);
		if (j == ss.size())
		{
			int k;
			M[i].len2 = 0;
			if (ss[0] == '-')
			{
				M[i].s1[0] = -1;
				for (k = 1; k < ss.size(); k++)
				{
					M[i].s1[k] = ss[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (ss[0] == '+')
			{
				M[i].s1[0] = 1;
				for (k = 1; k < ss.size(); k++)
				{
					M[i].s1[k] = ss[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (ss[0] >= '0'&&ss[0] <= '9')
			{
				M[i].s1[0] = 1;
				for (k = 0; k < ss.size(); k++)
				{
					M[i].s1[k + 1] = ss[k] - '0';
				}
				M[i].len1 = k + 1;
			}
		}
		else
		{
			int k;
			if (ss[0] == '-')
			{
				M[i].s1[0] = -1;
				for (k = 1; k < j; k++)
				{
					M[i].s1[k] = ss[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (ss[0] == '+')
			{
				M[i].s1[0] = 1;
				for (k = 1; k < j; k++)
				{
					M[i].s1[k] =ss[k] - '0';
				}
				M[i].len1 = k;
			}
			else if (ss[0] >= '0'&&ss[0] <= '9')
			{
				M[i].s1[0] = 1;
				for (k = 0; k <j; k++)
				{
					M[i].s1[k + 1] = ss[k] - '0';
				}
				M[i].len1 = k + 1;
			}
			int u = 0;
			for (k = j + 1; k < ss.size(); k++, u++)
				M[i].s2[u] = ss[k] - '0';
			M[i].len2 = u;
		}
	}
	sort(M.begin(), M.end(), cmp);
	for (int i = 0; i < T; i++)
		cout << M[i].s;
	return 0;
}
