#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*对于高精度计算问题，两种情况：
有些要计算完整结果，需要处理大数存储和计算的基本方法，即建立和使用数组，完成包括基本计算、进位、借位等操作。
有些不需要计算高精度数字的完整结果，可以通过一定的数学知识解决。*/
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