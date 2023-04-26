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

int cal(char c)
{
	int cnt = 0;
	while(c != 0)
	{
		if( c & 1 )
			cnt++;
		c = c>>1;				
	}
	
	return cnt;
}

int main()
{
	int t;
	scanf("%d",&t);
	int j;
	for(j = 0; j < t; j++)
	{	
		char c;
		int ans = 0 , cnt = 0;
		while((c = getchar()) != '\n')
			ans += cal(c) , cnt++;		
		
		cnt *= 8;
		
		int tmp = GCD(ans , cnt);
		
		printf("%d/%d\n",ans/tmp,cnt/tmp);
	}
	
	return 0;
}
