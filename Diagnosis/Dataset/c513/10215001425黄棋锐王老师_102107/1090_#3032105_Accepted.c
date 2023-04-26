#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() 
{  int N;/*N^N=(10*lgN)^N=(10^N)^lgN=10^a.b,
         10^0=1,10^1=10，1<10^0.b<10
         10^a.b=(10^a)*(10^0.b),首位数字看10^0.b的整数部分
 */
 
 
	while(scanf("%d",&N)&&N!=0)// 计算pow(10,N*lgN-(int)N*lgN) 
	{  double tmp=0,ans=0;
		tmp=N*(log(N)/log(10));//求a.b
		tmp-=(int)tmp;//求0.b
		ans=pow(10,tmp);//求10^0.b
		int t=(int)ans; //首位数字看10^0.b的整数部分
		printf("%d\n",t);
	}
	return 0;
}