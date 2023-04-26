#include <stdio.h> 
#include <string.h>
#define N 1000000


int main(void)
{
	char s[N + 1], subs[N + 1];
	scanf("%s", s);
	char *p1 = s, *p2 = s;
	int len = 0;
	int hashmap[128] = {0};
	while(*p2){
		if(hashmap[*p2] != 0){
			if(p2 - p1 > len){
				len = p2 - p1;
				memmove(subs, p1, len);
				subs[len] = '\0';
			}
			p1 = p2;
			memset(hashmap, 0, sizeof(hashmap));
		}else{
			hashmap[*p2] = 1;
			p2 ++;
		}
	}
	if(p2 - p1 > len){
		len = p2 - p1;
		memmove(subs, p1, len + 1);
		subs[len] = '\0';
	}
	printf("%s", subs);

	
	return 0;
}