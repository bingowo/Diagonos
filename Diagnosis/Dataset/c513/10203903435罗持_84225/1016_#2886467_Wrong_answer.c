#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char table[] = "0123456789ABCDEF";
const double esp = 1e-8;
void helper(int n,char s[],double r)
{
	int rm = 0,q = 0,t = (int)r;
	int idx = 28;
	while(n)
	{
		if(fabs(n/r)<esp) q = (int)(n/r);
		else q = ceil(n/r);
		rm = n-t*q;
		s[idx] = table[rm];
		idx--;
		n = q;
	}
	char ss[30];
	strcpy(ss,s+idx+1);
	strcpy(s,ss);
}
int main(void)
{
	int n,r;
	scanf("%d %d",&n,&r);
	char res[30] = {0};
	if(n==0) printf("0");
	else
	{
		helper(n,res,(double)r);
		printf("%s",res);
	} 
	return 0;
}