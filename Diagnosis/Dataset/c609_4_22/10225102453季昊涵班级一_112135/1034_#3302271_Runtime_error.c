#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char in[100006];

int main(){
	scanf("%s",&in);
	char *str1=in;
	char str2[3]="0x";
	int f=0;
	char out[1000][100];
	int i=0;
	while(strstr(str1,str2)!=NULL){
		char *p=strstr(str1,str2)+2;
		int k=0;
		while(*(p+k)<='f'&&*(p+k)!='\0'){
			f=1;
			out[i][k]=*(p+k);
			k++;
		}
		out[i][k]='\0';
		str1=p;
		i++;	
	}
	if(f==0)
	printf("-1");
	else{
		for(int k=0;k<i;k++){
			if(strlen(out[k])>0){
				unsigned int ans=0;
				int len=strlen(out[k]);
				for(int l=0;l<len;l++){
					if(out[k][l]>='a')
					ans=ans*16+out[k][l]-'a'+10;
					else
					ans=ans*16+out[k][l]-'0';
				}
				printf("%u ",ans);
			}
		}
	}
	return 0;
}