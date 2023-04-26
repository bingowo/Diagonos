#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size(char*  arr){ 
	char* start=arr;
	char* end=arr; 
	while(*end!='\0'){
		end++;
	}
	return end-start;
}
int text(char s[]) {
	int i=0;
	while(i<strlen(s)-1) {
		if(s[i]==s[i+1])
			return 1;
		i++;
	}
	return 0;
}
void f(char *s) 
{
	int i=0,k=0;
	char y[110];
	char*x=y;
	while(i<size(s)) {
		if(s[i]==s[i+1]&&i+1<size(s)) {
			int j = i;
			while(s[j]==s[j+1]&&j<size(s)-1)j++;
			i=j+1;
		} 
		else {
			x[k]=s[i];
			i++;k++;x[k]='\0';
		}
	}
	strcpy(s,x);
	if(text(x)&&x[0]!='\0')
		f(s);
}
void insert(int i,char c,char x[] )
{
	for(int j=109;j>i;j--)
	{
		x[j]=x[j-1];
	}
	x[i]=c;
}

int main() {
	int t;
	scanf("%d",&t);
	for(int k=0; k < t; k++) {
	    if(k==5)break;
		char s[110];
		scanf("%s",s);
		int sum=0;
		char x[110],y[110],z[110];
		for(int i = 0; i < strlen(s); i++) {
			strcpy(x,s);strcpy(y,s);strcpy(z,s);
			insert(i,'A',x);
			insert(i,'B',y);
			insert(i,'C',z);
			f(x);f(y);f(z);
			int a=size(x);
			int b=size(y);
			int c=size(z);
			int Min=((a>b?b:a)>c?c:(a>b?b:a));
			Min=strlen(s)+1-Min;
			sum=(sum>Min?sum:Min);
		}
		printf("case #%d:\n%d\n",k,sum);
	}
	
	return 0;
}
