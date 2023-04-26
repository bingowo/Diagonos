#include <stdio.h>
#include <math.h>
void main()
{
	int n,m;
	int a,i,j,c;

	scanf("%d",&n);
	for (m=n,j=1; ; m+=n,j++)
	{
		a = m;
		for (i=0; a!=0 ;i++)  /*求m的位数*/
		    a = a/10;
		for (a=m; i!=0 ; i-- )   /*判断m的各位是否为1或者0*/
		{
			c = a/pow(10,i-1);
			if (c!=0&&c!=1)     /*是&&不是||*/
				break;
			a = a-c*pow(10,i-1);
		}
		if (i==0)         /*如果循环数均为1或0，循环结束时i的值为0*/
		{
			printf("%d",m);
			break;
		}
		else 
		{
		    printf("-1");
		    break;
		}
	}	

}