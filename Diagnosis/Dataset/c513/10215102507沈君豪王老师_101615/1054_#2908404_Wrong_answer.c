#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define L 2100

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int m;
		scanf("%d", &m);
		char c = getchar();
		char s[L], line[m + 1];
		gets(s);
		int j = 0;
		printf("case #%d:\n", i);		
		while(s[j]){
			int SpaceNum = 0, isWord = 0, number = 0, isLast = 0;
			int average = 0, delta = 0, word = 0;
			while(s[j] == ' '){
				j ++;
			}
			while(number % m != m - 1  && s[j]){
				if(s[j] == ' '){
					SpaceNum ++;
					if(isWord == 1){
						word ++;
					}
					isWord = 0;
				}else{
					isWord = 1;
				}
				j ++, number ++;
			}
			if(s[j] == '\0'){
				isLast = 1;
				for(int k = number, l = j; k >= 0; k --){
					line[k] = s[l--];
				}
				printf("%s\n", line);
				break;
			}
			if(!isspace(s[j])){
				if(s[j] && !isspace(s[j + 1])){
					while(s[j] != ' '){
						j --, number --;	
					}
					j --, number --, SpaceNum --;
				}else{
					word ++;
				}
			}else{
				SpaceNum ++;
				while(s[j] == ' '){
					j --, SpaceNum --, number --;
				}
				if(isWord){
					isWord = 0;
					word ++;
				}
			}
			delta = m - (number + 1);
			if(word == 1){
				average = 1;
			}else{
				average = ceil((delta + SpaceNum) / (double)(word - 1));
			}
			int total = delta + SpaceNum;
			for(int k = m - 1, l = m - 1, step = 0; k >= 0 ; k --){
				if(s[j + 1 - m + k] != ' '){
					line[l --] = s[j + 1 - m + k];
				}else{
					for(int r = 0; r < average && total > 0; r ++){
						line[l --] = ' ';
						total --;
					}
					while(s[j + 1 - m + k] == ' '){
						k --;
					}
					k ++;
				}
			}
			line[m] = '\0';
			printf("%s\n", line);
			j ++;
		}
	}
	
	return 0;
}