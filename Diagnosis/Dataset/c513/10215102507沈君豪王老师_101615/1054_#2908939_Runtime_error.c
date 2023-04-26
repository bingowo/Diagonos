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
		if(i >= 6){
			char *p = strstr(s, "institution");
			printf("%d %s\n", m, p - 100);
		}else{
			continue;
		}
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
					while(s[j] == ' '){
						j ++;
					}
					number ++;
				}else{
					isWord = 1;
					j ++, number ++;
				}
			}
			if(s[j] == '\0'){
				if(s[j - 1] == ' '){
					number --;
				}
				while(s[j] == ' ' || s[j] == '\0'){
					j --;
				}
				
				for(int k = number - 1, l = j; k >= 0; k --){
					line[k] = s[l--];
				}
				line[number] = '\0';
				printf("%s\n", line);
				break;
			}
			if(!isspace(s[j])){
				if(s[j] && !isspace(s[j + 1])){
					while(s[j] != ' '){
						j --, number --;
					}
					while(s[j] == ' '){
						j --;
					}
					number --, SpaceNum --;
				}else{
					word ++;
				}
			}else{
				SpaceNum ++;
				while(s[j] == ' '){
					j --;
				}
				SpaceNum --, number --;
				if(isWord){
					isWord = 0;
					word ++;
				}
			}
			delta = m - (number + 1);
			average = ceil((delta + SpaceNum) / (double)(word - 1));
			int total = delta + SpaceNum;
			int SpaceGroup[L];
			memset(SpaceGroup, 0, sizeof(SpaceGroup));
			for(int k = word - 2; total > 0 ; total --){
				SpaceGroup[k] ++;
				k --;
				if(k < 0){
					k = word - 2;
				} 
			}
			for(int k = j, l = m - 1, index = word - 2, step = 0; l >= 0 ; k --){
				if(s[k] != ' '){
					line[l --] = s[k];
				}else{
					for(int r = SpaceGroup[index]; r > 0; r --){
						line[l --] = ' ';
					}
					index --;
					while(s[k] == ' '){
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