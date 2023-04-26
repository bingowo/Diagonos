#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
char s[100001];
unsigned int a[30000] = {-1};
unsigned int f(char c){
	int i;
	char s1[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	for(i = 0; i < 16; i++){
		if(c == s1[i])return i;
	} 
	return -1;
}
int stou(char s[], int num, int i){
    int len = strlen(s), sum = 0, flag = 0;
    for(;i < len; i++){
    	if((i < len - 2 && s[i] == '0' && s[i+1] == 'x' && f(s[i+2]) != -1) || f(s[i]) == -1)break;
        else flag = 1;
        sum = sum*16 + f(s[i]);
    }
    if(flag == 0)a[num - 1] = -1;
    else a[num - 1] = sum;//printf("%c %d,", s[i], i);
    return i-1;
}

int main(){
	int i, n, j, num = 0, flag1 = 0, flag2 = 0;
	unsigned int sum = 0;
	char temp[15] = {0};
	scanf("%s", &s);
	for(i = 0; i < strlen(s); i++){
		if((s[i] == '0' && s[i+1] == 'x') || i == strlen(s)-1){
            num++;//printf("%u\n", num);
            i = stou(s, num, i+2);
		}
    }
		//printf("%d\n", num);
    for(i = 0; i < num; i++){
        if(a[i] != -1){
			if(flag1)printf(" ");
            printf("%u", a[i]);
            flag2 = 1;
            flag1 = 1;
        }
    }
    if(flag2 == 0)printf("-1");
	return 0;
} 