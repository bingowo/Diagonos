//以/或//或/////为输出条件 
#include <stdio.h>
#include <string.h>
char morse[36][6]={
	".-","-...","-.-.","-..",".",
	"..-.","--.","....","..",".---",
	"-.-",".-..","--","-.","---",
	".--.","--.-",".-.","...","-",
	"..-","...-",".--","-..-","-.--",
	"--..",
	"-----",".----","..---","...--","....-",
	".....","-....","--...","---..","----."
};
void f(char num[],int sub){
	int i;
	if(sub==5){
		for(i=26;i<36;i++){
			if(strcmp(num,morse[i])==0){
				printf("%c",i-26+'0');
			}
		}
	}else{
		for(i=0;i<26;i++){
			if(strcmp(num,morse[i])==0){
				printf("%c",i+'A');
			}
		}
	}
}
int main(){
	int s;
	int i,t;scanf("%d",&t);
	for(i=0;i<t;i++){
		char source[1001];scanf("%s",source);
		printf("case #%d:\n",i);
		s=0;
		int j=0;char c,num[6];int sub=0;
		do{
		    num[0]=0;
			switch(s){
				case 0:
					c=source[j];
					if(c=='/'){
						s=1;
					}else if(c=='\0'){
						f(num,sub),sub=0;
					}else{
						num[sub++]=c,num[sub]='\0';
					}
					break;
				case 1:
					c=source[j];
					if(c=='/'){
						j++;
						s=2;
					}else if(c=='\0'){
						f(num,sub),sub=0;
					}else{
						f(num,sub),sub=0;
						num[sub++]=c,num[sub]='\0';
						s=0;
					}
					break;
				default:
					c=source[j];
					if(c=='/'){
						j++;
						f(num,sub),sub=0;
						printf(".");
						s=0;
					}else{
						if(c=='\0'){
							f(num,sub);
						}else{
							f(num,sub),sub=0;
							printf(" ");
							num[sub++]=c,num[sub]='\0';
							s=0;
						}
					}
			}
			j++;
		}while(source[j-1]);
		printf("\n");
	}
}
/*
3
.../---/...
-/..../../...///../...///--/---/.-./..././//-.-./---/-.././////-.../-.--/.
-./---///.----/..---/-----
10
.-/-.../-.-./-.././..-./--./..../../.---/-.-/.-../--/-./---/.--./--.-/.-./.../-/..-/...-/.--/-..-/-.--/--../-----/.----/..---/...--/....-/...../-..../--.../---../----.
.-///-...///-.-.///-..///.///..-.///--.///....///..///.---///-.-///.-..///--///-.///---///.--.///--.-///.-.///...///-///..-///...-///.--///-..-///-.--///--..///-----///.----///..---///...--///....-///.....///-....///--...///---..///----.///
.-/////-.../////-.-./////-../////./////..-./////--./////..../////../////.---/////-.-/////.-../////--/////-./////---/////.--./////--.-/////.-./////.../////-/////..-/////...-/////.--/////-..-/////-.--/////--../////-----/////.----/////..---/////...--/////....-/////...../////-..../////--.../////---../////----./////
*/