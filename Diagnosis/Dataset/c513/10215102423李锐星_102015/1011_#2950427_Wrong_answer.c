#include <stdio.h>
#include <string.h>

int main()
{
	char num_x[30];
	scanf("%s",num_x);
	long long num_b[100],cnt=0;
	unsigned long long number;
	long long shi=0,xu=0;
	for (int i=2;i<strlen(num_x);i++){
		if(num_x[i]>='1'&&num_x[i]<='9'){
			number=number*16+num_x[i]-'0';
		}
		else{
			number=number*16+num_x[i]-'A'+10;
		}
	}
	for (int i=0;number>0;i++){
		num_b[i]=number%2;
		number/=2;
		cnt++;
	}
	for (int i=0,j=cnt-1;i<j;i++,j--){
		int t;
		t=num_b[i];
		num_b[i]=num_b[j];
		num_b[j]=t;
	}
	for (int i=0;i<cnt;i++){
		long long a,b;
		a=shi;
		b=xu;
		shi=-a-b+num_b[i];
		xu=a-b;
	}
	if(xu>1){
		printf("%lld+%lldi\n",shi,xu);
	}
	else if(xu==1){
		printf("%lld+i\n",shi);
	}
	else if(xu<0){
		printf("%lld%lldi\n",shi,xu);
	}
	else{
		printf("%lld\n",shi);
	}
	return 0;
}