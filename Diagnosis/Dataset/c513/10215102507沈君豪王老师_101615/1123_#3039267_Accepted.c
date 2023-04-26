#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char s[21];
	int times;
}Info;



int cmp1(const void *a, const void *b)
{
	Info *pa = (Info *)a;
	Info *pb = (Info *)b;
	if(pa->times != pb->times){
		return pa->times - pb->times;
	}else{
		return strcmp(pa->s, pb->s);
	}
}

int cmp2(const void *a, const void *b)
{
	Info *pa = (Info *)a;
	Info *pb = (Info *)b;
	return strcmp(pa->s, pb->s);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	Info in[n];
	for(int i = 0 ; i < n ; i ++){
		int isFind = 0;
		scanf("%s", in[i].s);
		in[i].times = 1;
	}
	qsort(in, n, sizeof(Info), cmp2);
	int idx = 0;
	for(int j = 1; j < n ; j++){
		if(strcmp(in[idx].s, in[j].s) == 0){
			in[idx].times ++;
		}else{
			idx ++;
			strcpy(in[idx].s, in[j].s);
		}
	}
	qsort(in, idx + 1, sizeof(Info), cmp1);
	for(int i = 0 ; i < idx + 1; i ++){
		printf("%s\n", in[i].s);
	}
		
	return 0;
}