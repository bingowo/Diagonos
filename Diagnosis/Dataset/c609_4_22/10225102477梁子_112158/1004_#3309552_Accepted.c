#include<stdio.h>
#include<string.h>
void reverse(char s[]){
	int i,j,t;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		t=s[i];
		s[i]=s[j];
		s[j]=t;
	}
}

int main(){
	int m,n;
	char s[32];
	scanf("%d%s%d",&m,&s,&n);
	int j=strlen(s);
	int sum=0,i;
	for(i=0;i<j;i++){
		if(s[i]<='9'&&s[i]>='0'){
			sum=sum*m+s[i]-'0';
		}
		else if(s[i]<='f'&&s[i]>='a')
		sum=sum*m+10+s[i]-'a';
		else sum=sum*m+10+s[i]-'A';
	}
	char a[32];
	int k=0;
	char ss[]="0123456789ABCDEF";
	do{
		a[k]=ss[sum%n];
		sum=sum/n;
		k++;
	}while(sum);
	a[k]='\0';
	reverse(a);
	printf("%s",a);
	return 0;
}