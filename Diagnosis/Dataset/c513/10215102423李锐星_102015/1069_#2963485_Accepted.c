#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reverse(int n)
{
	int i;
	char s[20];
	for (i=0;n>0;i++){
		s[i]=n%10+'0';
		n/=10;
	}
	s[i]='\0';
	return atoi(s);
}

int check(int n)
{
	int i,j;
	char s[20];
	for (i=0;n>0;i++){
		s[i]=n%10+'0';
		n/=10;
	} 
	s[i]='\0';
	for (i=0,j=strlen(s)-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}
void f(int times,int n)
{
	int m;
	m=reverse(n);
	int s=m+n;
	times+=1;
	if(check(s)){
		printf("%d %d",times,s);
		return ;
	}
	else{
		return f(times,s);
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	f(0,n);
	return 0;
}