#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int binary(char a);
int GCD(int m, int n);

int main()
{
    int n;
    scanf("%d\n", &n);
    int cnt = 0;
    while(cnt < n)
    {
        char s[120];
        gets(s);
        char *s1;
        s1 = s;
        int p, q = 0;
        while(*s1)
        {
            p = binary(*s1);
            q += p;
            s1++;
        }
        int x = GCD(q, 8*strlen(s));
        printf("%d/%d\n", q/x,8*strlen(s)/x);
        cnt++;
    }
    return 0;
}

int GCD(int m,int n)
{
	if(n>m)
	{
		int z;
		z = m;
		m = n;
		n = z;
	}
	if(n == 0) return m;
	else if(m % n == 0) return n;
	while(n!=0 && m%n !=0)
	{
		int t = m % n;
		m = n;
		n = t;
	}
	return n;
}

int binary(char a)
{
    int m = 0;
    char n = 1;
    for(int i = 0; i < 8;i++,a = a>>1)
        m += (a & m);
    return m;
}