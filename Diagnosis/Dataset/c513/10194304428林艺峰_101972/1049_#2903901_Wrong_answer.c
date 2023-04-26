#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *words[510], str[510], word[510];
int cmp(const void *a, const void *b){
	const char **pa = a, **pb = b;
	return strcmp(*(pa), *(pb));
}
int main(){
	int t, i, j, k;
	scanf("%d", &t);
	gets(str);
	for(i = 0; i < t; ++i){
		gets(str);
		printf("case #%d:\n", i);
		int l = strlen(str), len_word = 0, num_word = 0;
		for(j = 0; j < l; ++j){
			if((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')){
				word[len_word++] = str[j];
			}
			else{
				word[len_word++] = 0;
				if(num_word != 0){
					int flag = 1;
					for(k = 0; k < num_word; ++k){
						if(strcmp(words[k], word) == 0)	flag = 0;
					}
					if(flag){
						words[num_word] = (char*)malloc(len_word+1);
						strcpy(words[num_word++], word);
					}
				}
				else{
					words[num_word] = (char*)malloc(len_word+1);
					strcpy(words[num_word++], word);
				}
				len_word = 0;
			}
		}
		qsort(words, num_word, sizeof(words[0]), cmp);
		for(j = 0; j < num_word; ++j){
			printf("%s ", words[j]);
			free(words[j]);
		}
		printf("\n"); 
	}
	return 0;
}