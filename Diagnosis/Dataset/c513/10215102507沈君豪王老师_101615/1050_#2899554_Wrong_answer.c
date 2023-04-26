#include <stdio.h>
#include <string.h>

char *strbstr(const char *str1, const char *str2)
{
	char * ret = NULL;
	char *p1 = str1, *p2 = str2;
	while(strstr(p1, p2) != NULL){
		ret = strstr(p1, p2);
		p1 += strlen(str2);
	}
	return ret;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		char s1[100], s2[100], s[100];
		scanf("%s %s %s", s1, s2, s);
		char *p1 = strstr(s, s1), *p2 = strbstr(s, s2);
		char *p3 = strstr(s, s2), *p4 = strbstr(s, s1); 
		int length1, length2; 
		if(p1 == p2){
			length1	= 0;
		}else{
			length1 = p2 - p1 - (strlen(s1));
		}
		if(p3 == p4){
			length2 = 0;
		}else{
			length2 = p4 - p3 - (strlen(s2));
		}
		int max = (length1 > length2) ? length1 : length2;
		printf("case #%d:\n", i);
		printf("%d\n", max);
	}
	
	return 0;
}