#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
double res()
{
	char s[101];
	scanf("%s",s);
	switch(s[0])
	{
		case '+':return res()+res();
		case '-':return res()-res();
		case '*':return res()*res();
		case '/':return res()/res();
		default:return atof(s);
	}
}

int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		double ans;
		ans=res();
		printf("case #%d:\n%f\n",i,ans);
	}
	return 0;
}