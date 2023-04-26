#include<stdio.h>
#include<string.h>
#define L 500
int len1, len2;
int Input(int a[], char s[]){
	int len;
	int i=0,j,k;
	while(s[i] && s[i]!='.') i++; //定位小数点
	len = i;
	for(j=i-1,k=L;j>=0;j--,k--) 
	a[k] = s[j]-'0'; //整数部分
	for(j=i+1,k=L+1;j<strlen(s);j++,k++) 
	a[k] = s[j]-'0'; //小数部分
	return len;
}

void add(int a[],int b[],int N){
	int i, len;
	len = len1 > len2 ? len1 : len2;
	for(i=2*L;i>L+N;i--){
		a[i] -= b[i];
		if(a[i] < 0){
			a[i-1]--; a[i] += 10;
		}
	}
	if(a[i+1] >= 5) a[i]++;
	for(;i>=0;i--){
		a[i] -= b[i];
		if(a[i] < 0){
			a[i-1]--; a[i] += 10;
		}
	}
}

void output(int a[],int N){
	int i=0;
	while(i<=L && a[i]==0) i++; //跳过前置0
	if(i>L) printf("0");//整数部分为0
	else{
		while(i<=L) printf("%d", a[i++]);
	}
	printf(".");//printf("%d\n", N);
	while(i<=L+N){
		printf("%d", a[i++]);
	}
	printf("\n");
}

int main(){
	int A[2*L+1]={0}, B[2*L+1]={0},N;
	char s1[2*L+1], s2[2*L+1];
	scanf("%s",&s1); 
	scanf("%s",&s2);
	len1 = Input(A, s1);
	len2 = Input(B, s2);
	scanf("%d", &N);
	if(len1 > len2){
		add(A,B,N); //A+=B
		output(A,N);
	}
	else if(len1 == len2){
		if(strcmp(s1, s2) > 0){
			add(A,B,N); //A+=B
			output(A,N);
		}
		else{
			add(B,A,N); //A+=B
			printf("-");
			output(B,N);
		}
	}
	else{
		add(B,A,N); //A+=B
		printf("-");
		output(B,N);
	}
	return 0;
}