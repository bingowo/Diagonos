#include<stdio.h>
#include<stdlib.h>
double solve()
{
	char s[100];
	scanf("%s",s);
	switch(s[0])
	{
		case '+':
			return solve()+solve();
			break;
		case '-':
			return solve()-solve();
			break;
		case '*':
			return solve()*solve();
			break;
		case '/':
			return solve()/solve();
			break;
		default:
			return atof(s);
			break;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%.6f\n",i,solve());
	}
	return 0;
} 