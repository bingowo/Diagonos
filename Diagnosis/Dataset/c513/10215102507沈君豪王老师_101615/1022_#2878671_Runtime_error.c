#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
	char username[500000];
	char host[500000];
}Address;

void split(char s1[], char s2[], char s[])
{
	char *po = s, *p = s;
	for(; *p != '@'; p++);
	memmove(s1, po, p - po);
	s1[p - po] = '\0';
	po = p;
	for(; *p; p ++);
	memmove(s2, po, p - po);
	s2[p - po] = '\0';
}

int cmp(const void *a, const void *b)
{
	Address *pa = (Address *)a;
	Address *pb = (Address *)b;
	if(strcmp(pa->host, pb->host) != 0){
		return strcmp(pa->host, pb->host);
	}else{
		return strcmp(pb->username, pa->username);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	Address input[n];
	char temp[1000001];
	for(int i = 0 ; i < n ; i ++){
		scanf("%s", temp);
		split(input[i].username, input[i].host, temp);
	}
	qsort(input, n, sizeof(Address), cmp);
	for(int i = 0 ; i < n ; i ++){
		printf("%s%s\n", input[i].username, input[i].host);
	}
	
	return 0;
}