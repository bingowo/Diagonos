#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int len,sign,i,c=~(~0<<8);
	char s[100];
	while(scanf("%s",s)){
		len=strlen(s);
		sign=0;
		for(i=0;i<len;++i){
			if(s[i]=='.'){
				sign=1;
				break;
			}
		}
		if(sign){
			double m=atof(s);
			unsigned long long l=*(unsigned long long *)(&m);
			for(i=0;i<8;++i){
				printf("%02x ",l&c);
				l>>=8;
			}
		}
		else{
			int n=atoi(s);
			for(i=0;i<4;++i){
				printf("%02x ",n&c);
				n>>=8;
			}
		}
		printf("\n");
	}
    return 0;
}