#include<stdio.h>
#include<string.h>
void to_binary(int a,int c){
	int i=0;
	int num[10]={0};
	while(a){
		num[i]=a%2;
		a=a/2;
		i++;
	}
	for(int j=0;j<c-i;j++){
		printf("0");
	}
	for(int j=i-1;j>=0;j--){
		printf("%d",num[j]);
	}
	
}
int main(){
	char s[510]="";
	scanf("%s",s);
	int len,p=0,temp=0;
	len=strlen(s);
	printf("0001");
	int x[10]={0};
	temp=len;
	while(temp){
		x[p]=temp%2;
		temp=temp/2;
		p++;
	}
	for(int q=0;q<10-p;q++){
		printf("0");
	}
	for(int q=p-1;q>=0;q--){
		printf("%d",x[q]);
	}
	int k=0,a=0,b=0,c=10;
	while(k<len){
		int t=0;
		while(k<len&&t<3){
			b=s[k]-'0';
		    a=a*10+b;
		    k++;
		    t++;
		}
		if(t==3) c=10;
		else if(t==2) c=7;
		else if(t==1) c=4;
		
		to_binary(a,c);
		
	}
	return 0;
} 