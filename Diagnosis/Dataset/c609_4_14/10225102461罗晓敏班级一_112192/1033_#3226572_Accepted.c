#include <stdio.h>
#include <string.h>
char ins[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(){
	int t,i;
	scanf("%d",&t);
	char num[101];
	int lnum;
	for(i=0;i<t;i++){
		scanf("%s",num);
		printf("case #%d:\n",i);
		lnum=strlen(num);
		int j=0;
		while(lnum-3>=0){
			putchar(ins[num[j]>>2]);
			putchar(ins[((num[j]&3)<<4)+(num[j+1]>>4)]);j++;
			putchar(ins[((num[j]&15)<<2)+(num[j+1]>>6)]);j++;
			putchar(ins[num[j]&63]);j++;
			lnum-=3;
		}
		if(lnum==1){
			putchar(ins[num[j]>>2]);
			putchar(ins[(num[j]&3)<<4]);
			putchar('=');putchar('=');putchar('\n');
		}else if(lnum==2){
			putchar(ins[num[j]>>2]);
			putchar(ins[((num[j]&3)<<4)+(num[j+1]>>4)]);j++;
			putchar(ins[(num[j]&15)<<2]);j++;
			putchar('=');putchar('\n');
		}else{
			putchar('\n');
		}
	}
	return 0;
} 