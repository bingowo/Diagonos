#include<stdio.h>
#include<string.h>
int main(){
	int a,b,i=0,j=0; char c[30];char d[30];
	scanf("%d ",&a); 
	while(scanf("%c",&c[i])!=EOF)i++; i=0;
	scanf("%d",&b);
	int sum=0; int e=strlen(c);
	while(i<=e-1){
		if(c[i]>='0'&&c[i]<='9') sum+=c[i]-'0';
		else if(c[i]>='a'&&c[i]<='f') sum+=c[i]-'a'+10;
		else sum+=c[i]-'A'+10; 
		if(i<e-1)sum*=a; i++;
	}
	while(sum!=0){
			if(sum%b>=10) d[j]='A'+sum%b-10;	
		 	else d[j]='0'+sum%b;
			sum=sum/b; j++;
		}
	int count=j;
	for(j=count-1;j>=0;j--) printf("%c",d[j]);
	return 0;
} 