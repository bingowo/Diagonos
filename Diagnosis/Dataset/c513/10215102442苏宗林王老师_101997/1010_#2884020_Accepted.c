#include<stdio.h>
#include<string.h>
void pr(int a,int n){
	int i=0,re[100];
	while(a>0){
		re[i]=a%2;
		a/=2;
		i++;
	}
	while(i<n){
		re[i]=0;
		i++;
	}
	for(int k=n-1;k>=0;k--){
		printf("%d",re[k]);
	}
}

int main(){
	int weight=100,a,i,n;
	char s[1000];
	scanf("%s",&s);
	n=strlen(s);
	printf("0001");
	pr(n,10);
	a=0;
	for(i=0;i<3*(n/3);i++){
		a+=weight*(s[i]-'0');
		if(weight>1)weight/=10;
		else {
			
			pr(a,10);
			weight=100;
			a=0;
		}
	}
	if(n%3==1){
		pr(s[i]-'0',4);
	}
	if(n%3==2){
		pr(10*(s[i]-'0')+s[i+1]-'0',7);
	}
	return 0;
}