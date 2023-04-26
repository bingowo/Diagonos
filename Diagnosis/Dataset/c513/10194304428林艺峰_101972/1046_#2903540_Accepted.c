#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *no_words[] = {"the", "a", "an", "of", "for", "and"};
char *words[110], word[110], str[110];
int tolower(int x){
	if(x >= 'A' && x <= 'Z'){
		return x - 'A' + 'a';
	}
	return x;
}
int main(){
	int t, i, j, k;
	scanf("%d", &t);
	gets(str);
	for(i = 0; i < t; ++i){
		gets(str);
		int l = strlen(str), len_word = 0, len = 0;
		for(j = 0; j < l; ++j){
			if(str[j] != ' ')	word[len_word++] = tolower(str[j]);
			else if(str[j] == ' '){
				word[len_word++] = 0;
				int flag = 0;
				for(k = 0; k < 6; ++k){
					if(strcmp(word, no_words[k]) == 0)	flag = 1;
				}
				if(!flag){
					words[len] = (char*)malloc(len_word+1);
					if(len != 0){
						int flag1 = 0;
						for(k = 0; k < len; ++k){
							if(strcmp(word, words[k]) == 0)	flag1 = 1;
						}
						if(!flag1)	strcpy(words[len++], word);
					}
					else if(len == 0)	strcpy(words[len++], word);
				}
				len_word = 0;
			}
		}
		int flag = 0;
		for(k = 0; k < 6; ++k){
			if(strcmp(word, no_words[k]) == 0)	flag = 1;
		}
		if(!flag){
			words[len] = (char*)malloc(len_word+1);
			if(len != 0){
				int flag1 = 0;
				for(k = 0; k < len; ++k){
					if(strcmp(word, words[k]) == 0)	flag1 = 1;
				}
				if(!flag1)	strcpy(words[len++], word);
			}
			else if(len == 0)	strcpy(words[len++], word);
		}
		for(k = 0; k < len; ++k)	free(words[k]);
		printf("case #%d:\n%d\n", i, len);
	}
	return 0;
}