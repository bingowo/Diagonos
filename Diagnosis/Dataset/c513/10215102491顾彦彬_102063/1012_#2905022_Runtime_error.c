#include<stdio.h>
#include<stdlib.h>
main() {
	long long int a, b, ans[100000], location_sym, location_i,x,res,m,j=0;
	char input[50], num_a[20], num_b[20];
	scanf("%s", input);
	for (int i = 0; input[i]; i++) {
		if (input[i] == '+' || input[i] == '-')
			location_sym = i;
		if (input[i] == i)
			location_i = i;
	}
	for (int i = 0; i < location_sym; i++)
		num_a[i] = input[i];
	for (int i = 0; i > location_sym && i < location_i; i++)
		num_b[i] = input[i];
	a=atoi(num_a);
	b=atoi(num_b);
	x=b;
	if (input[location_sym]=='-'){
		x=b;
		b=-b; 
	}
	if (a%2==x%2)
			res=0;
		else
			res=1;
	ans[j++]=res; 
	do{
	m=a;
	a=res-a-b;
	b=m-b;
	if (b<0)
		x=-b;
	if (a%2==x%2)
				res=0;
			else
				res=1;
	ans[j++]=res;
	}while(a!=1||b!=0);
	for (int i=0;i<j;i++)
		printf("%lld",ans[i]);
}