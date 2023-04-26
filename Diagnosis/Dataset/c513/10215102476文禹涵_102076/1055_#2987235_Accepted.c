#include <stdio.h> 
#include <string.h>
#define N 1000000

typedef struct{
	int isExist;
	int position;
}HashMap;


int main(void)
{
	char s[N + 1], subs[N + 1];
	scanf("%s", s);
	char *p1 = s, *p2 = s;
	int len = 0;
	HashMap map[128] = {{0, 0},};
	while(*p2){
		if(map[*p2].isExist != 0){
			if(p2 - p1 > len){
				len = p2 - p1;
				memmove(subs, p1, len);
				subs[len] = '\0';
			}
			p1 = p1 + map[*p2].position + 1;
			p2 = p1;
			memset(map, 0, sizeof(map));
		}else{
			map[*p2].isExist = 1;
			map[*p2].position = p2 - p1;
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
