#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{   int k,T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 { int m,n,i;
    scanf("%d %d",&m,&n);//组合数=m!/(n!(m-n)!) 
 	printf("case #%d:\n",k);
 	unsigned long long P=1;//计算结果
 	int large=1,small=1;
 	if(m>2*n) small=n,large=m-n;//取较小的数来做除数 
 	else small=m-n,large=n;
 	for(i=m;i>large;i--)//m*(m-1).........(m-large+1)，即m先除掉large的结果
 	{if(i==2*small)//两倍直接干掉，提高计算效率，~预处理 
 	{
 		P=P*2;
 		small--;
	 }
 	else P=P*i;
	 }
	while(small>1)//连除 
	{
		P=P/small;
		small--;
	}
 	printf("%llu\n",P);
 }
	
	return 0;
}