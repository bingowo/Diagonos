#include<stdio.h>
#include<string.h>

int main(){
	int n,r;
	char a[1000];
	scanf("%d %s %d",&n,a,&r);
	int temp=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]<='9')
		temp=temp*n+a[i]-'0';
		else if('a'<=a[i]&&a[i]<='f')
		temp=temp*n+a[i]-'a'+10;
		else
		temp=temp*n+a[i]-'A'+10;
	}
	int out[1000];
	int i=0;
	do{
		out[i]=temp%r;
		i++;
	}while(temp/=r);
	for(int k=i-1;k>=0;k--)
	printf("%d",out[k]);
	return 0; 
} 