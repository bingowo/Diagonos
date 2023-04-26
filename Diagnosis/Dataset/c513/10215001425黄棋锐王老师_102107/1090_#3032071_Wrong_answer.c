#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() 
{  int N;//N^N=(10*lgN)^N=(10^N)^lgN,10^N首位必为10的倍数，
 
	while(scanf("%d",&N)&&N!=0)// 计算pow(10,N*lgN-(int)N*lgN) ,10^1=10为两位，10的小数次方为一位数
	{  double tmp=0,ans=0;
		tmp=log(N)/log(10);
		tmp-=(int)tmp;
		ans=pow(10,tmp);//ans必定为个位数 
		int t=(int)ans;
		printf("%d\n",t);
	}
	return 0;
}