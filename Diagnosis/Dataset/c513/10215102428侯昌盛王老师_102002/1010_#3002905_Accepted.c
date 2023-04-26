#include <stdio.h>
#include <string.h>
int main()
{
	char s[501];
	scanf("%s",s);
	int len=strlen(s),z,zl;
	z=len/3;
	zl=len-z*3;
	char a[200][11];
	int i=0,k=1,h=0;
	while(i<z*3)
	{
	
		int num=0,j=i;
		for(j;j<i+3;j++)
		{
			num=num*10+s[j]-'0';
		}
		int m=9;
	//	printf("num=%d\n",num);
		while(num)
		{
			a[h][m--]=num%2+'0';
			num/=2;
		}
		int p=0;
		for(p;p<=m;p++) a[h][p]='0';
		a[h][10]='\0';
		i+=3;
		h++;
	}
	//printf("%s\n",a[0]);
	if(zl==2)
	{
		int num=0,j=z*3;
		for(j;j<i+2;j++)
		{
			num=num*10+s[j]-'0';
		}
		int m=6;
		while(num)
		{
			a[h][m--]=num%2+'0';
			num/=2;
		}
		int p=0;
		for(p;p<=m;p++) a[h][p]='0';
		a[h][7]='\0';
		h++; 
	}

	else if(zl==1)
	{
		int num=0,j=z*3;
		num=s[j]-'0';
		int m=3;
		while(num)
		{
			a[h][m--]=num%2+'0';
			num/=2;
		}
		int p=0;
		for(p;p<=m;p++) a[h][p]='0';
		a[h][4]='\0';
		h++;
	}
	int num2=len,e=9;
	
	char op[10];
	memset(op,'0',sizeof(op));
	while(num2)
	{
		op[e--]=num2%2+'0';
		num2/=2;	
	}
	op[10]='\0';
	printf("0001");
	printf("%s",op);
	int r=0;
	for(r;r<h;r++) printf("%s",a[r]);
	printf("\n");
	return 0;
}