#include<stdio.h>
#include<string.h>
int main(){
	char s[100001];
	scanf("%s",&s);
	unsigned int sum=0;
	int i;
	int key=0;
	int count=0;  //用来表示输出的次数
	int change=0; //用来表示在一次0x中有多少十六进制字符 
	for(i=0;i<strlen(s);i++){
		if(s[i]=='0'&&s[i+1]=='x'&&key==0){
			key=1;
			i++;
		}
		else if(s[i]>='0'&&s[i]<='9'&&key==1){
			sum=sum*16+s[i]-'0';
			change++;
			if(s[i+1]=='\0'){printf("%u ",sum);sum=0;count++;}
		}
		else if(s[i]>='a'&&s[i]<='f'&&key==1){
			sum=sum*16+s[i]-'a'+10;
			change++;
			if(s[i+1]=='\0'){printf("%u ",sum);sum=0;count++;}
		}
		else{
			if(key==1){
				if(change!=0) {printf("%u ",sum);count++;}
				sum=0;
				key=0;
		}
		}
	}
	if(count==0) printf("-1");
}