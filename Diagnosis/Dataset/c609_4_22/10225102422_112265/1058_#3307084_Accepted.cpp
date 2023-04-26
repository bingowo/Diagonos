#include<iostream>
#include<string>
#include<vector>
#define N 1000
using namespace std;
void dell(int* L, int* x, int* len)
{
	int c[N + 1];
	int b[N + 1];
	if (L[0] == 1)
	{
		for (int i = 1; i < *len; i++)
		{
			c[i] = (*x * 10 + L[i]) / 2;
			*x = (*x * 10 + L[i]) % 2;
		}
		c[0] = b[0] = -1;
		int lc = 1;
		int k = 1;
		while (c[lc] == 0 && lc < *len&&*len>2)lc++;
		for (k = 1; lc < *len; lc++, k++)
			b[k] = c[lc];
		for (int j = 0; j < k; j++)
			L[j] = b[j];
		*len = k;

	}
	else if (L[0] == -1)
	{
		c[0] = b[0] = 1;
		for (int i = 1; i < *len; i++)
		{
			c[i] = ((*x) * 10 + L[i]) / 2;
			*x = ((*x) * 10 + L[i]) % 2;
		}
		int lc = 1;
		int k = 1;
		while (c[lc] == 0 && lc < *len&&*len>2)lc++;
		for (k = 1; lc <*len; k++, lc++)
			b[k] = c[lc];
		if (*x == 1)
			b[k - 1]++;
		for (int j = 0; j < k; j++)
			L[j] = b[j];
		*len = k;

	}
}
int main()
{
	string s;
	getline(cin, s);
	int * L = new int[N + 1];
	int i = 0;
	int len;
	if (s[s.size() - 1] == '\n')
		s[s.size() - 1] = 0;
	if (s.size() == 1 && s[0] == '0') printf("%d\n", 0);
	else
	{
		if (s[0] == '-')
		{
			L[0] = -1;
			for (i = 1; i < s.size(); i++)
				L[i] = s[i] - '0';
			len = i;
		}
		else
		{
			L[0] = 1;
			for (i = 0; i < s.size(); i++)
				L[i + 1] = s[i] - '0';
			len = i + 1;
		}
		int x = 0;

		int* yu = new int[N + 1];
		i = 0;
		while (!(len == 2 && L[1] == 0))
		{
			x = 0;
			dell(L, &x, &len);
			yu[i] = x;
			i++;
		}
		delete[] L;
		for (int k = i - 1; k >= 0; k--)
			cout << yu[k];
		delete[] yu;
	}
}