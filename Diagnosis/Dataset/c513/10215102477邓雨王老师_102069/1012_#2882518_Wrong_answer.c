#include<stdio.h>
#include<string.h>
int main(){
	long long a=0,b=0;
	long long temp=0;
	long long n=1;
	char s[100];
	scanf("%s",&s);
	int i;
	for(i=0;i<=strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			temp=temp*10+s[i]-'0';
		}
		else if(s[i]=='-'&&i==0){
			if(s[i+1]!='i'){
		    	n=-1;
		    	temp=0;}
			else{
				n=-1;
				temp=1;	
			}
		}
		else if(s[i]=='-'&&i!=0){
			if(s[i+1]=='i'){
				a=temp*n;
				temp=1;
				n=-1;
			}
			else{
				a=temp*n;
				n=-1;
			}
		}
		else if(s[i]=='+'){
			if(s[i+1]!='i'){
			a=temp*n;
			temp=0;
			n=1;}
			else{
				a=temp*n;
				temp=1;
				n=1;
			}
		}
		else if(s[i]=='i'&&i!=0){
			b=temp*n;
			temp=0;
			n=1;
		}
		else if(s[i]=='i'&&i==0){
			a=0;
			b=1;
		}
		else if(s[i]=='\0'&&temp!=0){
			a=temp*n;
			temp=0;
			n=1;
		}
	}
	char t[1000];
	int j=0;
	long long qr,qi;
	if(a==0&&b==0){
		t[0]='0';
	}
	else{
	while(a!=0||b!=0){
		if((a-b)%2==0){
			t[j]='0';
			qr=a;
			qi=b;
			a=(-qr+qi)/2;
			b=(-qr-qi)/2;
			j=j+1;
		}
		else{
			qr=a;
			qi=b;
			t[j]='1';
			a=(1-qr+qi)/2;
			b=(-qr-qi+1)/2;
			j=j+1;
		}
	}
	t[j]='\0';
	}
	char c;
	for(i=0,j=strlen(t)-1;i<j;i++,j--) {//反转
         c=t[i],t[i]=t[j],t[j]=c;}

	printf("%s",t);
}