#include <stdio.h>
#include <string.h>
#define L 500

void input(int* a,char* s)
{
	int i,j;
	for (i=strlen(s)-1,j=L;i>=0;i--,j--){
		a[j]=s[i]-'0';
	}
}

void sub(int* a,int* b)
{
	int i;
	for (i=L;i>0;i--){
		a[i]-=b[i];
		if(a[i]<0){
			a[i]+=10;
			a[i-1]--;
		}
	}
}
void output(int* a)
{
	int i;
	while(i<=L&&a[i]==0)i++;
	if(i>L){
		printf("0\n");
	}
	else{
		for(;i<=L;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}
}

int main()
{
	int a[L+1]={0},b[L+1]={0};
	char s[L+1],t[L+1];
	while((scanf("%s %s",s,t))!=EOF){
		input(a,s);
		input(b,t);
		sub(a,b);
		output(a);
	}
	return 0;
}