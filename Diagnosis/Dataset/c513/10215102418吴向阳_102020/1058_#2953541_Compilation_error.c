#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct line
{
	string l;
	int judge;
};

line del(line m)
{
	int len = m.l.length();
	string t = m.l;
	for (int i = 0;i<len;i++)
	{
		if (m.judge==1)
		{
			for(int j = i;j<len;j++)
			{
				if (j == len-1 && m.l[j] != '/')
				{
					m.l.clear();
					return m;
				}
				if (m.l[j] == '*' && m.l[j+1] == '/')
				{
					m.judge=0;
					m.l.erase(0,j+2);
					return m;
				}
			}
		}
		else if (m.l[i] == '"')
		{
			for(int j = i+1;j<len;j++)
			{
				if (m.l[j] == '"') i=j+1;
			}
		}
		else if (m.l[i] == '/')
		{
			if (m.l[i+1] == '/')
			{
				t.erase(i,len-i);
				break;
			}
			else if (m.l[i+1] == '*')
			{
				for (int j=i+1;j<len;j++)
				{
					if (j == len-1 && m.l[j] != '/') m.judge=1;
					if (m.l[j] == '*' && m.l[j+1] == '/')
					{
						t.erase(i,j-i+2);
						break;
					}
				}
			}
		}
	}
	m.l.clear();
	m.l=t;
	return m;
}


int main(int argc,char *argv[])
{
	string str;
	line LINE;
	LINE.judge=0;
	while(getline(cin,str))
	{
		istringstream iss(str);
		while(iss>>LINE.l)
		{
			LINE = del(LINE);
			cout<<LINE.l<<endl;
		}
	}
	return 0;
}