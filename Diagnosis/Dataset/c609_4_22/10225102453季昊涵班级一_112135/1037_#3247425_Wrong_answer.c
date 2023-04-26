#include<stdio.h>
#include<string.h>

char s[1000086];

int main(){
	scanf("%s",s);
	int len=strlen(s);
	int begin=0;
	int max=0;
	for(int i=0;i<len-1;i++){
		int al[128]={0};
		int k=i+1;
		int temp=0;
			while(s[k]!=s[i]&&k<len&&al[s[k]]!=1){
			al[s[k]]=1;
			temp++;
			k++;
			}
		if(temp>=max){
			max=temp;
			begin=i;
		}	
	}
	for(int k=begin;k<=(begin+max);k++)
	printf("%c",s[k]);
	return 0; 
} 