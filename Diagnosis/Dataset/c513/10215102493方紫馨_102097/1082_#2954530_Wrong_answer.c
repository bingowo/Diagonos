#include<stdio.h>
#include<string.h>
void my_strchr(char A1[],char A[],int a){
	for(int i=0;a<strlen(A);a++,i++){
		A1[i] = A[a];
	}
}
void reserve(char s[]){
	int len = strlen(s)-1;
	for(int i=0,j=strlen(s)-1;i<j;i++,j--){
		char t;
		t=s[i];s[i]=s[j];s[j]=t;
	}
}
void reserve_(char s[],int n){
	for(int i=0,j=n-1;i<j;i++,j--){
		char t;
		t=s[i];s[i]=s[j];s[j]=t;
	}
}
int calculate(char ret[],char A[],char B[],int r){
	reserve(A);reserve(B);
	int i=0;
	int len_A = strlen(A);
	int len_B = strlen(B);
	for(;i<len_A||i<len_B;i++){
		if(i>=len_A)
			A[i]='0';
		if(i>=len_B)
			B[i]='0';
		r = r + A[i]+B[i]-'0'-'0';
		ret[i]=r%10;
		r/=10;
	}
	if(r!=0){
		ret[i] = r;i++;
	}
	ret[i] = '\0';
	if(len_A==0&&len_B==0){
		ret[0]=r;
		ret[1]='\0';
		i=1;
	}
	reserve_(ret,i);
	return i;
}
int main()
{
	char A[510]={'\0'},B[510]={'\0'};
	char A1[51]={'\0'},B1[51]={'\0'};
	int N,a=-1,b=-1;
	scanf("%s%s%d",A,B,&N);
	for(int i=0;i<strlen(A);i++){
		if(A[i]=='.'){
			a=i;			
			break;
		}
	}
	for(int i=0;i<strlen(B);i++){
		if(B[i]=='.'){
			b=i;			
			break;
		}
	}
	if(a!=-1){
		my_strchr(A1,A,a);
		A[a]='\0';
	}	
	if(b!=-1){
		my_strchr(B1,B,b);
		B[b]='\0';
	}	
		
	//A保存整数部分，A1保存小数部分； 
	int r=0;
	char ret1[510],ret2[N+10];
	if(A1[N+1]<9)	A1[N+1]+='0';
	if(B1[N+1]<9)	B1[N+1]+='0';
	r = A1[N+1] -'0'+ B1[N+1]-'0';
	r = (r+5)/10;
	int len_A1 = strlen(A1);
	int len_B1 = strlen(B1);
	for(int i=N;i>0;i--){
		if(i>=len_A1)
			A1[i]='0';
		if(i>=len_B1)
			B1[i]='0';	
		A1[i]-='0';B1[i]-='0';
		r = r + A1[i] + B1[i];
		ret2[i] = r%10;
		r/=10;
	}
	int m;
	m=calculate(ret1,A,B,r);
	for(int i=0;i<m;i++){
		printf("%d",ret1[i]);
	}
	printf(".");
	for(int i=1;i<=N;i++){
		printf("%d",ret2[i]);
	}
	
	return 0;
}