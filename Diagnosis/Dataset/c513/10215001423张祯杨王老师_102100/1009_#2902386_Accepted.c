#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a,int b) 
{
    if(b==0) 
		return a;
    return gcd(b,a%b);
}

int cal(char c)
{
	int cnt = 0;
	while(c != 0)
	{
		cnt++;
		c = c & (c - 1);				
	}
	
	return cnt;
}



int main()
{
	int t;
	scanf("%d\n",&t);
	int i;
	for(i = 0; i < t; i++)
	{	
		int ans_fenzi = 0 , ans_fenmu = 0; 
		int  j;
		char c;
		for( j = 0 ; ( c = getchar() ) != '\n' ; j++)
			ans_fenzi += cal(c);
		ans_fenmu = 8 * j;
		int g = gcd( ans_fenzi , ans_fenmu);
		ans_fenzi /= g;
		ans_fenmu /= g;
		
		printf("%d/%d\n",ans_fenzi,ans_fenmu);
	}
	
	return 0;
}
