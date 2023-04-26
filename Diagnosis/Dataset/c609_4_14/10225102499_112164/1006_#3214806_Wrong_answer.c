#include<stdio.h>
#include<string.h>

long long power(x,n){
	long long power=1;
	for(;n>0;n--)
		power*=x;
	return power;
}

long long min(char *a){
	int i,j,k,r,temp;
	char b[60]={0};
	long long answer=0;
	b[0]=a[0];
	for(i=1;i<strlen(a);i++){
		for(temp=0,j=0;j<strlen(b);j++){
			if(a[i]==b[j]){
				j++;
				break;
			}
			if(a[i]!=b[j])
				temp++;
		}
		if(temp==j&&j!=0)
			b[strlen(b)]=a[i];
	}
	r=strlen(b);
	for(i=0;i<strlen(a);i++){
			if(a[i]==b[0])
				a[i]='1';
		}
	for(i=0;i<strlen(a);i++){
			if(a[i]==b[1])
				a[i]='0';
		}
	for(j=2;j<strlen(b);j++){
		for(i=0;i<strlen(a);i++){
			if(a[i]==b[j])
				a[i]='0'+j;
		}
	}
	for(i=strlen(a)-1,k=0;i>=0;i--,k++){
		answer+=(a[i]-'0')*power(r,k);
	}
	return answer;
}

int main(){
	int i,T;
	char a[10][60]={0};
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%s",a[i]);
		printf("case #%d:\n%d\n",i,min(a[i]));
	}
	return 0;
} 