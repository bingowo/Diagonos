#include <stdio.h>
#include <string.h>

int pow(int a,int b){
	int c=1;
	for(int i=0;i<b;i++) c*=a;
	return c;
}

int GCD(int a,int b){
	return b==0?a:GCD(b,a%b);
}

int main(){
	int A=0,B=0,C=0;
	char num[35];
	scanf("%s",num);
	int len=strlen(num);
	int i=0;
	while(num[i]!='.'){
		i++;
		if(i==len){
			i=len;
			break;
		}
	}
	for(int j=i-1;j>-1;j--){
		if(num[j]=='2') A+=(-1)*pow(3,i-1-j);
		else A+=(num[j]-'0')*pow(3,i-1-j);
	}
	int k=len-1;
	C=pow(3,len-i-1);
	for (int j=0;j<len-i-1;j++){
		if(num[k-j]=='2') B=B*3-1;
		else B=(num[k-j]-'0')+B*3;
	}
	while((B<0)&&(A>0)){
		A-=1;
		B=C+B;
	}
	if(A<0){
		A+=1;
		B=C-B;
	}
	int n=GCD(B,C)<0?-GCD(B,C):GCD(B,C);
	if(A==0) printf("%d %d",B/n,C/n);
	else if(B==0) printf("%d",A);
	else printf("%d %d %d",A,B/n,C/n);
	return 0;
}