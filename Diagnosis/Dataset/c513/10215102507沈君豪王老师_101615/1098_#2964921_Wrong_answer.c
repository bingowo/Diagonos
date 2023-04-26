#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t ; i ++)
	{
		char s[120];
		scanf("%s", s);
		char *p = s;
		int light[4] = {0}, jdx = 0;
		int idx = 0, b[4]= {0};
		while(*p){
			if(*p != '!' && light[idx % 4] == 0){
				light[idx % 4] = *p;
			}
			p ++, idx ++;
		}
//		for(int i = 0 ; i < 4; i ++){
//			printf("%c", light[i]);
//		}
		p = s, idx = 0;
		while(*p){
			if(*p == '!'){
				char c = light[idx % 4];
				switch(c){
					case 'R': b[0]++ ; break;
					case 'B': b[1]++ ; break;
					case 'Y': b[2]++ ; break;
					case 'G': b[3]++ ; break;
				}
			}
			p ++, idx ++;
		}
		printf("case #%d:\n", i);
		for(int i = 0 ; i < 4;  i ++){
			printf("%d%c", b[i], i == 3 ? '\n' : ' ');
		}
	}
	
	return 0;
}