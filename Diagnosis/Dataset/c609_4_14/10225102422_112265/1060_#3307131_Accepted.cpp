#include<iostream>
#include<string>
#define N 100
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	char S[2 * N + 1];
	int j = 0;
	if (s.size() == 1) cout << s;
	else
	{
		int i;
		for (i = 0; i < s.size() - 1;)
		{
			if (s[i] < s[i + 1])
			{
				S[j] = s[i];
				j++;
				S[j] = s[i];
				j++;
				i++;
			}
			else if (s[i]>s[i + 1])
			{
				S[j] = s[i];
				j++;
				i++;
			}
			else if (s[i] == s[i + 1])
			{
				int index = i;
				for (; index < s.size() - 1; index++)
				{
					if (s[index] != s[index + 1])
						break;
				}
				if (index == s.size() - 1)
				{
					S[j] = s[i];
					j++;
					i++;
				}
				else
				{
					int length = index - i + 1;
					char c = s[i];
					int k = 0;
					for (k = 1; k <= length; k++)
					{
						if (s[i + k] != c)
							break;
					}
					if (s[i + k] > c)
					{
						for (int n = 1; n <= k; n++)
						{
							S[j] = s[i];
							j++;
							S[j] = s[i];
							j++;
							i++;
						}
					}
					else
					{
						for (int n = 1; n <= k - 1; n++)
						{
							S[j] = s[i];
							j++;
							i++;
						}
					}
				}
			}
		}
		S[j] = s[i];
		j++;
		S[j] = 0;
		cout << S;
	}
	return 0;
}