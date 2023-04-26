#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char s[1111];
int f(char *a,char *b)
{
	int t = 0;
	for(char *i = a; i != b; i++)
	{
		t *= 10;
		t += (*i) - '0';
	}
	return t;
}
signed main()
{
	gets(s);
	int l = strlen(s);
	bool neg = false, neg2 = false;
	int pos = 0;
	if(s[0] == '-')
    {
        neg = true;
        pos++;}
	for( ; pos < l; pos++)
	{
		if(s[pos] == '+') break;
		if(s[pos] == '-')
        {
            neg2 = true;
            break;
        }
	}
	int x = 0,y = 0;
	if(s[l-1] == 'i' && pos == l)
    {
        y = (neg == pos - 1 ? 1 : f(s+neg,s+l-1));
        if(neg)
            y = -y;
    }
	else if(pos == l)
    {
        x = f(s+neg,s+pos);
        if(neg)
            x = -x;
    }
	else
	{
		x = f(s+neg,s+pos);
		if(neg)
            x = -x;
		y = (pos + 1 == l - 1 ? 1 : f(s+pos+1,s+l-1));
		if(neg2)
            y = -y;
	}
	long long a = x, b = y, a1,b1;
	int d[1111];
	if(a == 0 && b == 0)
        printf("0");
	long long m=1;
	while(a != 0 || b != 0)
	{
		a1 = a % 2;
		b1 = b % 2;
		d[m] = (a1 & 1)^(b1 & 1);
		long long ta = -a + b,tb = -a - b;
		a = ta;
		b = tb;
		if(a % 2 == 1 || a % 2 == -1)
		{
			a++;
			b++;
		}
		a /= 2;
		b /= 2;
		m++;
	}
	for(long long i = m - 1; i > 0; i--)
        printf("%d",d[i]);
	printf("\n");
	return 0;
}



