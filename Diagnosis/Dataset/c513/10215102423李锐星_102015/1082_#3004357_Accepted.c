#include <stdio.h>
#include <string.h>
#define L 500

void input(int* a)
{
	char s[L+1];
	scanf("%s",s);
	int i=0;
	while(i<strlen(s)&&s[i]!='.') i++;
	
	int j,k;
	for (j=i-1,k=L;j>=0;j--,k--){
		a[k]=s[j]-'0';
	}
	for (j=i+1,k=L+1;j<strlen(s);j++,k++){
		a[k]=s[j]-'0';
	}
}

void add(int* a,int* b,int n)
{
	int i;
	for (i=2*L;i>L+n;i--){
		a[i]+=b[i];
		a[i-1]+=a[i]/10;
		a[i]=a[i]%10;
	}
	if(a[i+1]>=5){
		a[i]++;
	}
	for (i;i>0;i--){
		a[i]+=b[i];
		a[i-1]+=a[i]/10;
		a[i]=a[i]%10;
	}
}

void output(int* a,int N)
{
	int i=0;
	while(i<=L&&a[i]==0)i++;
	if(i>L){
		printf("0");
	}
	else{
		while(i<L+1){
			printf("%d",a[i]);
			i++;
		}
	}
	printf(".");
	while(i<=L+N){
		printf("%d",a[i]);
		i++;
	}
	printf("\n");
	
}
int main()
{
	int A[2*L+1]={0},B[2*L+1]={0};
	input(A);
	input(B);
	int N;
	scanf("%d",&N);
	add(A,B,N);
	output(A,N);
	return 0;
}