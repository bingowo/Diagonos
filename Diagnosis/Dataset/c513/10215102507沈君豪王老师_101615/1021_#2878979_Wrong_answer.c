#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int map[26];
typedef struct{
	char s[30];
}Word;
void CreateMap(char s[])
{
	char *p = s, index = 0;
	while(*p){
		map[*p - 'A'] = index;
		p ++, index ++;
	}
}

int cmp(const void *a, const void *b)
{
	Word *pa = (Word *)a;
	Word *pb = (Word *)b;
	char *ppa = pa->s, *ppb = pb->s; 
	for(; toupper(*ppa) == toupper(*ppb); ppa ++, ppb ++);
	return map[toupper(*ppa) - 'A'] - map[toupper(*ppb) - 'A'];
}

int main(void)
{
	char maps[27];
	scanf("%s", maps);
	CreateMap(maps);
	char c = getchar();
	int index = 0, line = 0;
	Word words[100];
	while((c = getchar()) != EOF){
		if(c == ' '){
			words[line].s[index] = '\0';
			line ++;
			index = 0;
		}else if(c == '\n'){
			words[line].s[index] = '\0';
			qsort(words, line + 1 , sizeof(Word), cmp);
			for(int i = 0 ; i < line + 1; i ++){
				printf("%s%c", words[i].s, i == line ? '\n' : ' ');
			}
			scanf("%s", maps);
			CreateMap(maps);
			c = getchar();
			line = 0, index = 0;
		}else{
			words[line].s[index] = c;
			index ++;			
		}
	}
	
	return 0;
}