#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1010], cha[2010];
char toupper(char c){
	if(c >= 'a' && c <= 'z')	return c - 'a' + 'A';
	else	return c;
}
int main(int argc, char *argv[]){
	scanf("%s", &str);
	int l = strlen(str), head = 0, tail = 0, i;
	cha[head] = str[0];
	for(i = 1; i < l; ++i){
		if(toupper(str[i]) >= toupper(cha[head])){
			head--;
			cha[head] = toupper(str[i]);
		}
		else{
			tail++;
			cha[tail] = toupper(str[i]);
		}
	}
	for(i = head; i <= tail; ++i){
		printf("%c", cha[i]);
	}
	return 0;
}