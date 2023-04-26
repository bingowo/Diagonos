#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char word[15];
}List;

int cmp(const void *a, const void *b)
{
	List * pa = (List *)a;
	List * pb = (List *)b;
	return strcmp(pb->word, pa->word);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	List in[n];
	char s[6000];
	for(int i = 0 ; i < n ; i ++)
	{
		scanf("%s", in[i].word);
	}
	scanf("%s", s);
	char *p = s, *pf = NULL;
	qsort(in, n, sizeof(List), cmp);
	while(*p){
		int index;
		for(index = 0, pf = NULL; index < n; index ++){
			pf = strstr(p, in[index].word);
			if(pf != p){
				pf = NULL;
			}else{
				break;
			}
		}
		if(!pf){
			printf("%c ", *p);
			p++;
		}else{
			printf("%s ", in[index].word);
			p += strlen(in[index].word);
		}
	}
}