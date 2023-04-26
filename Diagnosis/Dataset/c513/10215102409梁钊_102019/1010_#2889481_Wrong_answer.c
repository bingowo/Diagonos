#include<stdio.h>
#include<string.h>

int main()
{
	char n[501]={'0'};
	scanf("%s",&n);
	int slen = strlen(n) ;
	int num = slen / 3 ;
	int tmp=0;
	char s[50000]={'0'};
	char* p = s ;
	if(slen%3==0);
	if(slen%3==1){
		tmp=(int)(n[slen-1]-'0');
		for(int i=0;i!=4;i++){
			*(p++) = (char)((1 & tmp) + '0');
			tmp = tmp >> 1 ;
		}
	}
	else{
		tmp=(int)(n[slen-1]-'0')+10*(int)(n[slen-2]-'0');
		for(int i=0;i!=7;i++){
			*(p++) = (char)((1 & tmp) + '0');
			tmp = tmp >> 1 ;
		}		
	}
	for(int i=slen/3-1;i!=-1;i--){
		if(i==0){
			tmp=100*(int)(n[0]-'0')+10*(int)(n[1]-'0')+(int)(n[2]-'0');
			for(int j=0;j!=10;j++){
				*(p++) = (char)((1 & tmp) + '0') ;
				tmp = tmp >> 1 ; 
			}
		}
		else{
			tmp=100*(int)(n[i*3]-'0')+10*(int)(n[i*3+1]-'0')+(int)(n[i*3+2]-'0');
			for(int i=0;i!=10;i++){
				*(p++) = (char)((1 & tmp) + '0') ;
				tmp = tmp >> 1 ;
			}
		}
	}
	for(int i=0;i!=10;i++){
		*(p++) = (char)((1 & slen) + '0');
		slen = slen >> 1 ;
	}
	printf("0001");
	for(int i=strlen(s)-1;i!=-1;i--)
	printf("%c",s[i]);
}
