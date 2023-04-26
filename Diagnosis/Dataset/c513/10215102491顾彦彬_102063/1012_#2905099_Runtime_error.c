#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main() {
	long long int a, b, ans[100000], location_sym, location_i,x,y,res,m,j=0,sign=1;
	char input[50], num_a[20]={}, num_b[20]={};
	scanf("%s", input);
	if(input[0]=='-'){
		sign=-1;
		for (int i=0;input[i+1];i++)
			input[i]=input[i+1];
		input[strlen(input)-1]='\0';
	}
	
	for (int i = 0; input[i]; i++) {
		if (input[i] == '+' || input[i] == '-')
			location_sym = i;
		if (input[i] == 'i')
			location_i = i;
	}
	for (int i = 0; i < location_sym; i++)
		num_a[i] = input[i];
	j=0;
	for (int i = 0; i > location_sym && i < location_i; i++)
		num_b[j++] = input[i];
	a=atoi(num_a)*sign;
	b=atoi(num_b);
	if (location_i-location_sym==1)
		b=1;
	x=b;
	if (input[location_sym]=='-')
		b=-b; 
	if ((a*sign)%2==x%2)
			res=0;
		else
			res=1;
	ans[j++]=res; 
	do{
	m=a;
	a=res-a-b;
	b=m-b;
	x=b;
	y=a;
	if (b<0)
		x=-b;
	if (a<0)
		y=-a;
	if (y%2==x%2)
				res=0;
			else
				res=1;
	ans[j++]=res;
	}while(a!=1||b!=0);
	for (int i=0;i<j;i++)
		printf("%lld",ans[i]);
}