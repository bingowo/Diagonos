#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int num[100][100];
char bin[9];
int binary(int i,int j){
	int a,ret = 0;
	if(num[i-1][j-1]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[0] = a;
	if(num[i-1][j]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[1] = a;
	if(num[i-1][j+1]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[2] = a;
	if(num[i][j+1]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[3] = a;
	if(num[i+1][j+1]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[4] = a;	
	if(num[i+1][j]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[5] = a;
	if(num[i+1][j-1]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[6] = a;
	if(num[i][j-1]<num[i][j])
		a = 0;
	else
		a = 1;
	ret = ret*2 + a;
	bin[7] = a;
	return ret;
}

int compare(int b){
	int last,a=b,min=b;
	for(int i=0;i<7;i++){
		last = bin[i];		
		a = (a<<1)&255 ;
		a += last;
		if(min>a)
			min = a;
	}
	return min;
}

int main()
{
	const int n,m;
	scanf("%d%d",&n,&m);
	//输入 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&num[i][j]);
		}
	}
	int b;
	for(int i=1;i<m-1;i++){
		for(int j=1;j<n-1;j++){
			b = binary(i,j);
			printf("%d%c",compare(b),j==n-2?'\n':' ');
		}
	}
	
	
	return 0;
}