#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ins[123];
int main(){
	int i,j;
	for(i=0;i<123;i++)ins[i]=-1;
	char s[1000001];scanf("%s",s);
	int tou=0,maxtou=0,ret=0;
	for(i=0;s[i];i++){
		if(ins[s[i]]>=tou){
			tou=ins[s[i]]+1;
			ins[s[i]]=i;
		}else{
			ins[s[i]]=i;
			if(ret<i-tou+1){
				maxtou=tou;
				ret=i-tou+1;
			}
		}
	}
	for(i=maxtou;i<maxtou+ret;i++)
	printf("%c",s[i]);
}