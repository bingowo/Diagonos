#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char s2[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char str[52] = {'\0'};
float d[126] = {0};
char m[110] = {'\0'};

int fun(char c){
	int i = 0;
	for(i = 0; i < 54; i++){
		if(c == str[i])break;
	}
	return i;
}

int cmp1(const void *a, const void *b){
    int i = 0; char *pa = (char *)a, *pb = (char *)b;
    //printf("%f", s[i]);
    return d[*pa]>d[*pb]?-1:1; 
}

int cmp2(const void *a, const void *b){
    int i = 0; char *pa = (char *)a, *pb = (char *)b;
	return fun(*pa) > fun(*pb)?1:-1;
}

int main(){
	int i = 0, num = 0, j, t;
	scanf("%d", &t);
	for(j = 0; j < t; j++){
		for(i = 0; i < 26; i++){
			scanf("%f", &d[i+65]);
		}
		qsort(s, 26, sizeof(char), cmp1);
		for(i = 0; i < 52; i+=2){
			str[i] = s[i/2]+32;
			str[i+1] = s[i/2];
		}
		scanf("%s", m);
		qsort(m, strlen(m), sizeof(char), cmp2);
		printf("case #%d:\n", j);
		printf("%s\n", m);
		for(i = 0; i < 26; i++){
			s[i] = s2[i];
		}
	}
}