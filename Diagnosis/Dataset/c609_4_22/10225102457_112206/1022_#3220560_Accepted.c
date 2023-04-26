#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* p1, const void* p2);

int main(void)
{
	int n;
	scanf("%d",&n);

	char *input[n];
	for(int i = 0; i < n; i++){
		char in[1000001];
		scanf("%s",in);
		input[i] = (char*)malloc(strlen(in) * sizeof(char) + 1);
		strncpy(input[i],in,strlen(in)+1);
	}

	qsort(input, n, sizeof(input[0]), cmp);

	for(int i = 0; i < n; i++){
		printf("%s\n",input[i]);
	}

	for(int i = 0; i < n; i++){
		free(input[i]);
	}
	
	return 0;
}

int cmp(const void* p1, const void* p2)
{
	char *a = *(char**)p1;
	char *b = *(char**)p2;
	char *test_a = a;
	char *test_b = b;
	//printf("##%s\n",test_a);

	while(*test_a != '@') test_a++;
	while(*test_b != '@') test_b++;

	while(*test_a != '\0' && *test_b != '\0'){
		if(*test_a != *test_b) return *test_a - *test_b;
		test_a++;
		test_b++;
	}
	if(*test_a != *test_b) return *test_a - *test_b;

	test_a = a, test_b = b;
	while(*test_a != '@' && *test_b != '@'){
		if(*test_a != *test_b) return *test_b - *test_a;
		test_a++;
		test_b++;
	}
	if(*test_a == '\0') return 1;
	else if(*test_b == '\0') return -1;
	else return 0;
}