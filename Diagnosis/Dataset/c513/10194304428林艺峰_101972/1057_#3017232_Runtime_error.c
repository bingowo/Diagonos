#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1010], cha[2010];
char toup(char c){
	if(c >= 'a' && c <= 'z')	return c - 'a' + 'A';
	else	return c;
}
int main(int argc, char *argv[]){
	scanf("%s", &str);
	int l = strlen(str), head = 0, tail = 0, i;
	for(i = 0; i < l; ++i)	str[i] = toup(str[i]);
	cha[head] = str[0];
	for(i = 1; i < l; ++i){
		if(str[i] >= cha[head]){
			head--;
			cha[head] = str[i];
		}
		else{
			tail++;
			cha[tail] = str[i];
		}
	}
	for(i = head; i <= tail; ++i){
		printf("%c", cha[i]);
	}
	return 0;
}