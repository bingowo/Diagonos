#include<stdio.h>
#include<string.h>
int main(){
	char s[100001];
	scanf("%s",&s);
	unsigned int sum=0;
	int i;
	int key=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='0'&&s[i+1]=='x'&&key==0){
			key=1;
			i++;
		}
		else if(s[i]>='0'&&s[i]<='9'&&key==1){
			sum=sum*16+s[i]-'0';
			if(s[i+1]=='\0') printf("%d ",sum);
		}
		else if(s[i]>='a'&&s[i]<='f'&&key==1){
			sum=sum*16+s[i]-'a'+10;
			if(s[i+1]=='\0') printf("%d ",sum);
		}
		else{
			if(key==1){
				if(sum>0) printf("%d ",sum);
				sum=0;
				key=0;
		}
		}
	}
}