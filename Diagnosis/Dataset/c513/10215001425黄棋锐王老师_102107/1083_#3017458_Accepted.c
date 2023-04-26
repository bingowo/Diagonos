#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() 
{   int k,T;//找n！右端0个数=找10的几次方整除n！=找n！因式分解中的因子5的个数
 scanf("%d\n",&T);
 for(k=0;k<T;k++)
 { int n;
    scanf("%d",&n);
 	printf("case #%d:\n",k);
 	int count=n/5+n/25+n/125+n/625;
 	printf("%d\n",count);
} 
	return 0;
}