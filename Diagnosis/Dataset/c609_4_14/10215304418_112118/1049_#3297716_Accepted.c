#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char* x,char* y){
	if (strlen(x)!=strlen(y)){
		return strlen(x)-strlen(y);
	}
	else {
		int i=0;
		while (x[i]==y[i] && i<strlen(x)) i++;
		if (i<strlen(x)) return x[i]-y[i];
		else return 0;
	}
}

int main(){
	char a[1234],b[1234];
	while (scanf("%s %s",a,b)!=EOF){
		int f=check(a,b);
		if (f==0) {
			printf("0\n");
			continue;
		}
		if (f<0){
			char temp[1234];
			strcpy(temp,a);
			strcpy(a,b);
			strcpy(b,temp);
		}
		char numa[1234]={0},numb[1234]={0};
		for (int i=0;i<strlen(a);i++){
			numa[strlen(a)-i]=a[i]-'0';
			if (i<strlen(b)){
				numb[strlen(b)-i]=b[i]-'0';
			}
			else numb[strlen(b)-i]=0;
		}
		int ans[1234]={0};
		for (int i=1;i<=strlen(a);i++){
			if (numa[i]>=numb[i]){
				ans[i]=numa[i]-numb[i];
			}
			else{
				numa[i]+=10;
				numa[i+1]-=1;
				ans[i]=numa[i]-numb[i];
			}
		}
		if (f<0) printf("-");
		int i=strlen(a);
		while (ans[i]==0) i--;
		for (;i>=1;i--){
			printf("%d",ans[i]);
		}
		printf("\n");
	}
    return 0;
}

