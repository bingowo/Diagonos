#include <stdio.h>
#include <string.h>

void insert(char s[300], int pos) {
	int len = strlen(s);
	for (int i = len+1; i > pos; i--) {
		s[i] = s[i-1];
	}
}

int main() {
	char s[300];
	scanf("%s", s);
	int len = strlen(s);
	
	for(int i = 0; i < len; i++) {
		insert(s, i);
		i++; len++;
	}
	printf("%s\n" ,s);
	
	
	return 0;
}