#include <stdio.h>
#include <string.h>
int ins[123];
int main(){
	int i,j;
	for(i=0;i<123;i++)ins[i]=-1;
	char s[1000001];scanf("%s",s);
	int tou=0,maxtou=0,ret=0;
	for(i=0;s[i];i++){
		if(ins[s[i]]<tou){
			ins[s[i]]=i;
		}else if(ins[s[i]]>=tou){
			ret=i-tou;
			break;
		}
	}
	if(s[i]==0)ret=strlen(s);
	for(j=i;s[j];j++){
		if(ins[s[j]]<tou){
			ins[s[j]]=j;
		}else if(j-tou>ret){
				ret=j-tou;
				maxtou=tou;
				tou=ins[s[j]]+1;
				ins[s[j]]=j;
		}else{
				tou=ins[s[j]]+1;
				ins[s[j]]=j;
		}
	}
	for(i=maxtou;i<maxtou+ret;i++)
	printf("%c",s[i]);
}