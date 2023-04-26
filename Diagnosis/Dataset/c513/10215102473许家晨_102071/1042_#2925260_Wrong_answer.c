#include<string.h>
#include<stdio.h>
void readstr(char *s,int *res){
	while(*s){
		if(*s>='a'){
			if(res[*s-'a'+26]==0)res[*s-'a'+26]=1;
			s++;
		}	
		else{
			if(res[*s-'A']==0)res[*s-'A']=1;
			s++;
		}
	}
}
void print(char *s,int len){
	if(len==1){
		printf("%c\n",*s);
	}
	else{
		printf("%c",*s);
		print((++s),len-1);
	}
}
int main(){
	char input[16];
	char alpha[52]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char character[16]={'\0'};
	int dic[52];
	int i,j;
	for(i=0;i<52;i++){
		dic[i]=0;
	}
	scanf("%s",input);
	readstr(input,dic);
	for(i=0,j=0;i<52;i++){
		if(dic[i]==1){
			character[j++]=alpha[i];
		}
	}
	int max_len=strlen(character);
	
	for(i=0;i<strlen(character);i++){
		int now_len=1;
		char* pc=&character[i];
		while(now_len<=max_len){
			print(pc,now_len);
			now_len++;
		}
		max_len--;
	}
	return 0;
}