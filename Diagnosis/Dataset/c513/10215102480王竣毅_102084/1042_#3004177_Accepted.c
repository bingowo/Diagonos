#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
	char s[20];
}Str;

int cmp1(const void *a, const void *b)
{
	int na = *(int *)a;
	int nb = *(int *)b;
	return na - nb;
}

int cmp2(const void *a, const void *b)
{
	Str * pa = (Str *)a;
	Str * pb = (Str *)b;
	return strcmp(pa->s, pb->s);
}

int main(void)
{
	int t, c;
	scanf("%d", &t);
	c = getchar();
	for(int i = 0 ;i < t; i ++){
		int s[20] = {0, }, index = 0, map[52] = {0, }, id;
		while((c = getchar()) != '\n'){
			if(islower(c)){
				id = (c - 'a') * 2 + 1;
			}else{
				id = (c - 'A') * 2;
			}
			if(map[id] == 0){
				s[index ++] = c;
				map[id] = 1;
			}
		}
		Str data[1 << index];
		qsort(s, index, sizeof(int), cmp1);

		for(int j = 1; j < (1 << index); j ++){
			int p = 0;
			for(int k = 0; k < index; k ++){
				if(j & (1 << k)){
					data[j - 1].s[p ++] = s[k];
				}
			}
			data[j - 1].s[p] = '\0';
		}
		qsort(data, (1 << index) - 1, sizeof(Str), cmp2);
		printf("case #%d:\n", i);
		for(int j = 0 ; j < (1 << index) - 1; j ++){
			printf("%s\n", data[j].s);
		}
	}
	
	return 0;
 } 