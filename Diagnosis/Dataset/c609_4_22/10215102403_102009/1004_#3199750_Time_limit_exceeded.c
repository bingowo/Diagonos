#include<stdio.h>
#include<string.h>
int main(){
	int a,b,i=0,j=0; char c;char d[30];
	scanf("%d ",&a); 
	//while(scanf("%c",&c[i])!=EOF)i++; i=0;
	scanf("%d",&b);
	int sum=0; //int e=strlen(c);
	//while(i<=e-1)
	while(scanf("%c",&c)!=' '){
		if(c>='0'&&c<='9') sum+=c-'0';
		else if(c>='a'&&c<='f') sum+=c-'a'+10;
		else sum+=c-'A'+10; 
		sum*=a; 
	} sum/=a;
	while(sum!=0){
			if(sum%b>=10) d[j]='A'+sum%b-10;	
		 	else d[j]='0'+sum%b;
			sum=sum/b; j++;
		}
	int count=j;
	for(j=count-1;j>=0;j--) printf("%c",d[j]);
	return 0;
} 