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
	int t;scanf("%d",&t);getchar();
	char c;int s=0;
	char num[6];int sub=0;
	int i;
	printf("case #0:\n");
	for(i=0;i<t;)
	switch(s){
		case 0:
			c=getchar();
			if(c=='/'){
				f(num,sub),sub=0;
				s=1;
			}else if(c=='\n'){
				f(num,sub),sub=0;
				i++;
				if(i<t)printf("\ncase #%d:\n",i);
				continue;
			}else{
				num[sub++]=c,num[sub]='\0';
			}
			break;
		case 1:
			c=getchar();
			if(c=='/'){
				getchar();
				s=2;
			}else{
				num[sub++]=c,num[sub]='\0';
				s=0;
			}
			break;
		default:
			c=getchar();
			if(c=='/'){
				getchar();
				printf(".");
				s=0;
			}else{
				printf(" ");
				num[sub++]=c,num[sub]='\0';
				s=0;
			}
	}
}
/*
3
.../---/...
-/..../../...///../...///--/---/.-./..././//-.-./---/-.././////-.../-.--/.
-./---///.----/..---/-----
*/
