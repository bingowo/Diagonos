#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int T;
char a[100][20] = {0};
double st[111] = {0};
int fuhao(char s[])
{
	if(s[0]=='+') return 1;
	if(s[0]=='-') return 1;
	if(s[0]=='*') return 1;
	if(s[0]=='/') return 1;
	return 0;
}
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		memset(a,0,sizeof(a));
		memset(st,0,sizeof(st));
		char s[111] = {0};
		int idx = 0;
		while(scanf("%s",s)!=EOF)
		{
			char c = getchar();
			strcpy(a[idx++],s);
			if(c=='\n') break;
		}
		int top = 0;
		for(int i=idx-1;i>=0;i--)
		{
			if(!fuhao(a[i])){
				st[top++] = atof(a[i]);
				//printf("%f\n",st[top-1]);
			}
			else{
				top--;
				double x = st[top];
				top--;
				double y = st[top];
				double res = 0;
				if(a[i][0]=='+') res=x+y;
				if(a[i][0]=='-') res=x-y;
				if(a[i][0]=='*') res=x*y;
				if(a[i][0]=='/') res=x/y;
				st[top++] = res;
			}
		}
		printf("case #%d:\n",kase);
		printf("%.6f\n",st[0]);
	} 
	return 0;
}