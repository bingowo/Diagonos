#include<stdio.h>
#include<math.h>
long long binary(int n){
	int s[8];
	int d=1;
	for(int i=0;i<8;i++){
		if(n&d)
			s[7-i]=1;
		else
			s[7-i]=0;
		d*=2;
	}
	int ret=0;
	for(int i=0;i<8;i++){
		ret=ret*10+s[i];
	}
	return ret;
}

int main()
{
	int A;
	scanf("%d",&A);
	//M<2^8;
	long long M;
	for(int i=2;i<pow(2,8);i++){
		M=binary(i);
		if(M%A==0){
			printf("%llld",M);
			return 0;
		}
	}	
	printf("-1");
	return 0;
 } 