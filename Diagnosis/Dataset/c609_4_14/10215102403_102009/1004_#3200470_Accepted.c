#include<stdio.h>
#include<string.h>
int main(){
	int a,b,i=0,j=0; char c[30];char d[30];
	scanf("%d",&a); 
	scanf("%s",c);
	if(c[0]=='0'&&(!c[1])) {
		printf("0"); return 0;
	}
	int count=strlen(c); 
	scanf("%d",&b);
	int sum=0; 
	while(i<count){
		if(c[i]>='0'&&c[i]<='9') sum+=c[i]-'0';
		else if(c[i]>='a'&&c[i]<='f') sum+=c[i]-'a'+10;
		else sum+=c[i]-'A'+10; 
		sum*=a; i++;
	} sum/=a;
	while(sum){
		if(sum%b>=10) d[j]='A'+sum%b-10;	
	 	else d[j]='0'+sum%b;
		sum=sum/b; j++;
	}
	for(j=j-1;j>=0;j--) printf("%c",d[j]);
	return 0;
} 