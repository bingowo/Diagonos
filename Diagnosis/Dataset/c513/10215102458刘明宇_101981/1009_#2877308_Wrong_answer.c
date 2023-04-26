#include <stdio.h>
#include <stdlib.h>

int GCD(int m, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while(cnt < n)
    {
        char s[120];
        gets(s);
        int sum1 = 0;
        for(int i = 0;i < 8;i++)
        {
            if((*s) & 1) sum1++;
            *s >>=1;
        }
        printf("%d", sum1);
        //int x = GCD(sum1, 32);
        //printf("%d/%d", sum1/x,32/x);
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
