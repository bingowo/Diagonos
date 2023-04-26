#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[1100], ans[20], temp[20];
void print(int x){
	if(x < 10)	printf("0%d", x);
	else	printf("%d", x); 
}
int main(){
	int hh = 0, mm = 0, ss = 0;
	while(scanf("%s", &str)){
		if(str[0] == 'E' && str[1] == 'N' && str[2] == 'D')	break;
		int l = strlen(str), i, space = 0;
		for(i = 0; i < l; ++i){
			if(str[i] == ',')	str[i] = 0;
			if(str[i] == 0 && !space) space = i;
		}
		if(strcmp(str, "$GPRMC") == 0){
			temp[0] = str[space + 1];
			temp[1] = str[space + 2];
			hh = (atoi(temp) + 8) % 24;
			temp[0] = str[space + 3];
			temp[1] = str[space + 4];
			mm = atoi(temp);
			temp[0] = str[space + 5];
			temp[1] = str[space + 6];
			ss = atoi(temp);
		}
	}
	print(hh);printf(":");print(mm);printf(":");print(ss);
	return 0;
}