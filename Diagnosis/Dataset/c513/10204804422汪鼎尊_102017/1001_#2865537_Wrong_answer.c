#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char t(int i)
{
	return i<9?i+'0':i-10+'A';
}

int main()
{
	int n;
	int r,i,j,cases,c,p,neg;
	char result[33];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		p=0;neg=0;
		scanf("%d%d",&n,&r);
		if(n<0)neg=1;
		do{
			result[p]=t(abs(n%r));
			n=n/r;
			p++;
		}while(n!=0);
		if(neg==1)putchar('-');
		for(p--;p>=0;p--)putchar(result[p]);
		if(c!=cases-1)putchar('\n');
	}
	
	
	return 0;
}