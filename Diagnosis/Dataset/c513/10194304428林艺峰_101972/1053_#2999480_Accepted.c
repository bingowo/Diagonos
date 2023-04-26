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
		int l = strlen(str), i, space1 = 0, begin = 0, end = 0, space2 = 0;
		for(i = 0; i < l; ++i){
			if(str[i] == ',')	str[i] = 0;
			if(str[i] == 0 && space1 && !space2)	space2 = i;
			if(str[i] == 0 && !space1) space1 = i;
			if(str[i] == '$')	begin = i;
			if(str[i] == '*')	end = i;
		}
		if(strcmp(str, "$GPRMC") == 0 && str[space2 + 1] == 'A'){
			int flag = 0;
			int c = str[begin+1], c0 = 0;
			for(i = begin + 2; i < end; ++i){
				if(str[i] == 0){
					c = (c ^ ',') % 65535;
				}
				else{
					c = (c ^ str[i]) % 65535;
				}
			}
			sscanf(str+end+1, "%x", &c0);
			if(c == c0){
				temp[0] = str[space1 + 1];
				temp[1] = str[space1 + 2];
				hh = (atoi(temp) + 8) % 24;
				temp[0] = str[space1 + 3];
				temp[1] = str[space1 + 4];
				mm = atoi(temp);
				temp[0] = str[space1 + 5];
				temp[1] = str[space1 + 6];
				ss = atoi(temp);
			}
		}
	}
	print(hh);printf(":");print(mm);printf(":");print(ss);
	return 0;
}