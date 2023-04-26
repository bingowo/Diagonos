#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int text(char s[]) {
	int i=0;
	while(i<strlen(s)-1) {
		if(s[i]==s[i+1])
			return 1;
		i++;
	}
	return 0;
}
char* f(char s[]) {
	int i=0,k=0;
	char y[110];
	char*x=y;
	while(i<strlen(s)) {
		if(s[i]==s[i+1]&&i+1<strlen(s)) {
			int j = i;
			while(s[j]==s[j+1]&&j<strlen(s)-1)j++;
			i=j+1;
		} 
		else {
			x[k]=s[i];
			i++;k++;
		}
	}
	if(text(x)&&x[0]!='\0')
		return f(x);
	else
		return x;
}
void insert(int i,char c,char x[] )
{
	for(int j=109;j>i;j--)
	{
		x[j]=x[j-1];
	}
	x[i]=c;
}
int size(char *x)
{
	int i=0;
	while(x[i]!='\0')
	{
		i++;
	}
	return i;
}
int main() {
	int t;
	scanf("%d",&t);
	for(int k=0; k < t; k++) {
		char s[110];
		scanf("%s",s);
		int sum=0;
		char x[110],y[110],z[110];
		for(int i = 0; i < strlen(s); i++) {
			strcpy(x,s);strcpy(y,s);strcpy(z,s);
			insert(i,'A',x);
			insert(i,'B',y);
			insert(i,'C',z);
			int a=size(f(x));
			int b=size(f(y));
			int c=size(f(z));
			int Min=((a>b?b:a)>c?c:(a>b?b:a));
			Min=strlen(s)+1-Min;
			sum=(sum>Min?sum:Min);
		}
		printf("case #%d:\n%d\n",k,sum);
	}
	
	return 0;
}
