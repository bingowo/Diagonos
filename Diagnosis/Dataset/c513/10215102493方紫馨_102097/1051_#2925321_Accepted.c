#include<stdio.h>
#include<string.h>
void dec_binary3(int a,int b,int c,char binary[]){
	for(int i=128,k=0;i>=1;i=i>>1,k++){
		if(i&a)
			binary[k]=1;
		else
			binary[k]=0;
		if(i&b)
			binary[k+8]=1;
		else
			binary[k+8]=0;
		if(i&c)
			binary[k+16]=1;
		else
			binary[k+16]=0;
	}
}
void dec_binary2(int a,int b,char binary[]){
	for(int i=128,k=0;i>=1;i=i>>1,k++){
		if(i&a)
			binary[k]=1;
		else
			binary[k]=0;
		if(i&b)
			binary[k+8]=1;
		else
			binary[k+8]=0;
	}
	binary[16]=0,binary[17]=0;
}
void dec_binary1(int n,char* binary){
	for(int i=128,k=0;i>=1;i=i>>1,k++){
		if(i&n)
			binary[k]=1;
		else
			binary[k]=0;
	}
	binary[8]=0;binary[9]=0;binary[10]=0;binary[11]=0;
}
void print(int n){
	if(n>=0&&n<=25)
		printf("%c",n+'A');
	if(n>=26&&n<=51)
		printf("%c",n-26+'a');
	if(n>=52&&n<=61)
		printf("%d",n-52);
	if(n==62)
		printf("+");
	if(n==63)
		printf("/");
}
void binary_dec(char binary[],int n){
	for(int i=0;i<6*n;i+=6){
		int sum=0;
		for(int j=0;j<6;j++){
			sum = sum*2+binary[i+j];
		}
		print(sum);
	}
}
int main() 
{
 	int T;
 	scanf("%d",&T);
 	for(int i=0;i<T;i++){
 		char binary[25];
		char s[101];
		scanf("%s",s);
		int len = strlen(s);
		int a,b,c;
		printf("case #%d:\n",i);
		int j=0;
		for(j=0;j<len-2;j+=3){
			a = s[j];
			b = s[j+1];
			c = s[j+2];
			dec_binary3(a,b,c,binary);
			binary_dec(binary,4);
		}	
		if(j==len-2){
			dec_binary2(s[j],s[j+1],binary);
			binary_dec(binary,3);
			printf("=");
		}
		if(j==len-1){
			dec_binary1(s[j],binary);
			binary_dec(binary,2);
			printf("==");
		}
		printf("\n");		
	 }
	 return 0;
}