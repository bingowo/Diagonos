#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char word[4010][20];
char ans[5010][20];
char str[5010];
int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%s", &word[i]);
	}
	scanf("%s", &str);
	int l = strlen(str), head = 0, tail = l, len = 0;
	while(head < l){
		tail = (head + 15 >= l) ? l : head + 20;
		for(i = tail; i > head; --i){
			char c = str[i];
			str[i] = 0;
			if(i == head + 1){
				strcpy(ans[len++], str+head);
				head = i;
				str[i] = c;
				break;
			}
			for(j = 0; j < n; ++j){
				if(!strcmp(str+head, word[j])){
					strcpy(ans[len++], str+head);
					head = i;
					break;
				}
			}
			str[i] = c;
		}
	}
	for(i = 0; i < len; ++i){
		printf("%s", ans[i]);
		printf("%c", i == len - 1 ? '\n' : ' ');
	}
}