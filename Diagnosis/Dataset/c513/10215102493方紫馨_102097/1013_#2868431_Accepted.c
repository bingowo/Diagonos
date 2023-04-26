#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char num[100];
	scanf("%s",num);
	long long int i=0,a=0,b=0,c,k;
	for(;i<strlen(num)&&num[i]!='.';i++){
		if(num[i]=='2')
				k=-1;
		else if(num[i]=='0') 
				k=0;
		else if(num[i]=='1')
				k=1;
		a=3*a+k;
	}
	if(i==strlen(num)){
		printf("%lld",a);
		return 0;
	}
	c=pow(3,-i+strlen(num)-1);
	i++;
	for(;i<strlen(num);i++){
		if(num[i]=='2')
				k=-1;
		else if(num[i]=='0') 
				k=0;
		else if(num[i]=='1')
				k=1;
		b=b*3+k;
	}
	if(a>0&&b<0){
		a=a-1;
		b=c+b;
	}
	if(a<0&&b>0){
		a+=1;
		b=c-b;
	}
	if(a==0){
		printf("%lld %lld",b,c);
		return 0;
	}
	printf("%lld %lld %lld",a,b,c);
	return 0;
 } 