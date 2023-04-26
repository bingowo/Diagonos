#include <stdio.h>
#include<string.h>
#include<ctype.h>
char s[120];
int num = 0;
void con(){
	char c[120];int i, j = 0;
	for(i=0; i<strlen(s); i++){
		if(s[i] == ' '){
			c[j] = '\0';j = 0;//printf("%s\n", c);
			if(strcmp(c, "for") == 0);
			else if(strcmp(c, "a") == 0);
			else if(strcmp(c, "an") == 0);
			else if(strcmp(c, "the") == 0);
			else if(strcmp(c, "of") == 0);
			else if(strcmp(c, "and") == 0);
			else num++;
			continue;
		}
		c[j] = s[i]<='Z'?s[i]+32:s[i]; j++;
	}
	c[j] = '\0';j = 0;//printf("%d\n", num);
	if(strcmp(c, "for") == 0);
	else if(strcmp(c, "a") == 0);
	else if(strcmp(c, "an") == 0);
	else if(strcmp(c, "the") == 0);
	else if(strcmp(c, "of") == 0);
	else if(strcmp(c, "and") == 0);
	else num++;
}
int main(){
	int i, t;
	scanf("%d", &t);gets(s);
	for(i = 0; i < t; i++){
		gets(s);
		con();
		printf("case #%d:\n", i);
		printf("%d\n", num);
		num = 0;
	}
    
	return 0;
}

		
	