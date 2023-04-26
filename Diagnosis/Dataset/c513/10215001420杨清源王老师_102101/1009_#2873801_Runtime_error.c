#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a,int b)
{
    while(a!=b)
    {
    	if(a>b)
        	a=a-b;
        else if(a<b)
        	b=b-a;    
    }
    return a; 
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
		for(; (c = getchar()) != '\n' ; cnt++)
			ans += cal(c);
		
		cnt *= 8;
		
		int tmp = gcd(ans , cnt);
		
		printf("%d/%d\n",ans/tmp,cnt/tmp);
	}
	
	return 0;
}
