#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char link[301];
	char protocol[6];
	char domain[300];
	char vadd[300];
}Website;

void SplitLink(Website *p)
{
	char *pa = p->link;
	char *pb = pa + 1;
	
	while(*pb != ':'){
		pb ++;
	}
	memmove(p->protocol, pa, pb - pa);
	(p->protocol)[pb - pa] = '\0';
	pb += 4;
	pa = pb - 1;
	
	while(*pb != '/'){
		pb ++;
	}
	memmove(p->domain, pa, pb - pa);
	(p->domain)[pb - pa] = '\0';
	pb += 2;
	pa = pb - 1;
	
	while(*pb){
		pb ++;
	}
	memmove(p->vadd, pa, pb - pa);
	(p->domain)[pb - pa] = '\0';
}

int cmp(const void *a, const void *b)
{
	Website *pa = (Website *)a;
	Website *pb = (Website *)b;
	if(strcmp(pb->domain, pa->domain) != 0){
		return strcmp(pa->domain, pb->domain);
	}else{
		return strcmp(pa->vadd, pb->vadd);
	}
	
}

int main(void)
{
	int n;
	scanf("%d", &n);
	Website input[n];
	for(int j = 0 ; j < n ; j ++){
		scanf("%s", input[j].link);
		SplitLink(&input[j]);
	}
	qsort(input, n, sizeof(Website), cmp);
	for(int j = 0 ; j < n ; j ++){
		if(strcmp(input[j].protocol, "https") != 0){
			printf("%s\n", input[j].link);
		}
	}
	
	return 0;
}