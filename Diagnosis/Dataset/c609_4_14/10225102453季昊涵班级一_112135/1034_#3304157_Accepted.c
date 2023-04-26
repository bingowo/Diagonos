#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char in[100006];

int main(){
	scanf("%s",&in);
	char *str1=in;
	char str2[3]="0x";
	unsigned int out[10000]={0};
	int i=0;
	int yy=0;
	while(strstr(str1,str2)!=NULL){
		char *p=strstr(str1,str2)+2;
		int k=0;
		int f=0;
		unsigned int ans=0;
		while(*(p+k)<='f'&&*(p+k)!='\0'){
			f=1;
			yy=1;
				if(*(p+k)>='a')
					ans=ans*16+*(p+k)-'a'+10;
				else
					ans=ans*16+*(p+k)-'0';		
			k++;
		}
		out[i]=ans;
		str1=p;
		if(f==1)
		i++;	
	}
	if(yy==0)
	printf("-1");
	else{
		for(int k=0;k<i;k++){
			printf("%u ",out[k]);
		}
	}
		
	
	return 0;
}