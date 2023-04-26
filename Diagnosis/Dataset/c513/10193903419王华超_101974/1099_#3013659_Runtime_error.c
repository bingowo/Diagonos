#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int T;
	scanf("%d",&T);
	getchar();
	char table[][6]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	for(int cas=0;cas<T;cas++){
		printf("case #%d:\n",cas);
		char line[101];
		gets(line);
		for(int i=0;i<strlen(line);i++){
			if(i<=strlen(line)-5&&line[i]=='/'&&line[i+1]=='/'&&line[i+2]=='/'&&line[i+3]=='/'&&line[i+4]=='/'){
				printf(".");
				i=i+4;
			}
			else if(i<=strlen(line)-3&&line[i]=='/'&&line[i+1]=='/'&&line[i+2]=='/'){
				printf(" ");
				i=i+2;
			}
			else if(line[i]=='/'){
				printf("");
			}
			else{
				char letter[6];
				int len=0;
				int j=i;
				while(line[j]=='.'||line[j]=='-'){
					letter[j-i]=line[j];
					len++;
					j++;
				}
				for(int k=0;k<36;k++){
					if(strncmp(letter,table[k],len)==0&&len==strlen(table[k])){
						if(k<10){
							printf("%d",k);
						}
						else{
							printf("%c",k+55);
						}
					}
				}
				i=i+len-1;
			}
			
		}
		printf("\n");
	}
	return 0;
}