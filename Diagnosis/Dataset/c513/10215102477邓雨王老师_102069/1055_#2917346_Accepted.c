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
	//利用一张ASCII码的表（数组）来快速判断是否有重复的字符出现 
	while(*p2){
		if(map[*p2].isExist != 0){
			if(p2 - p1 > len){
				len = p2 - p1;
				memmove(subs, p1, len);
				subs[len] = '\0';
			}
			p1 = p1 + map[*p2].position + 1;
			/*这里的移动不需要逐个，而是直接跳转到重复出现字母之第
			一个的位置之后，例如：
			 alskhpoh   ==>   alskhpoh
			 ^                     ^
			 其中^表示p1的位置 
			*/
			p2 = p1;
			memset(map, 0, sizeof(map));
		}else{
			map[*p2].isExist = 1;
			map[*p2].position = p2 - p1;
			p2 ++;
		}
	}
	//while循环日常保护 
	if(p2 - p1 > len){
		len = p2 - p1;
		memmove(subs, p1, len + 1);
		subs[len] = '\0';
	}
	printf("%s", subs);

	
	return 0;
}