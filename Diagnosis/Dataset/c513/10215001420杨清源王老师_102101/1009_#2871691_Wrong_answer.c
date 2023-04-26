#include <stdio.h>
#include <string.h>

int GCD(int m, int n)
{
    int i, temp;
    if (m < n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    for (i = n; i > 0; i--)
        if (m % i == 0 && n % i == 0)
        {
            return i;
            break;
        }
}


int main()
{
	int t;
	scanf("%d",&t);
	int j;
	for(j = 0; j < t; j++)
	{
		char s[120], c;
		int len = strlen(s);
		int cnt = 0 , i = 0 , k , cmp = 1;
		
		while( c = getchar() != EOF)
			s[i++] = c;
		
		for(i = 0; i < len; i++)
		{
			for( k = 0; k < 8; k++)
			{
				if(s[i]&cmp)
					cnt++;
				cmp = cmp << 1;
			}
		
		}
		
		int tmp = GCD(cnt , 8*len);
		
		printf("%d/%d\n",cnt/tmp,8*len/tmp);
	}
	
	return 0;
}