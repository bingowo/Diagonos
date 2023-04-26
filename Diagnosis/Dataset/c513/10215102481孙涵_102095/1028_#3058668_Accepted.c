#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmpA(const void* a, const void* b);
int cmpD(const void* a, const void* b);

int main(int argc, char *argv[]) {
	char c;
	scanf("%c",&c);
	int s[100];
	int *p = s;
	int length = 0;
	while (scanf("%d",p++) != EOF){
		length++;
	}
	if (length == 1){
		printf("%d",s[0]);
		return 0;
	}
	if (c == 'A'){  //升序
		qsort(s,length,sizeof(s[0]),cmpA);
	}else if (c == 'D'){ //降序
		qsort(s,length,sizeof(s[0]),cmpD);
	}
	int i,j;
	for ( i = 0; i < length - 2; i++){
		if (s[i] == s[i + 1]){
			for (j = i+1; j < length - 1; j++){
				s[j] = s[j+1];
			}
			i--;
			s[length-1] = 0;
			length --;
		}
	}
	int count = 0;
	for (i = 0; i < length-1; i++){
		printf("%d ",s[i]);
		count ++;
	}
	if (count != length && s[length-1] != s[i-1]){
		printf("%d",s[length-1]);
	}
	return 0;
}

int cmpA(const void* a, const void* b){
	return *((int *)a) - *((int *)b);
}

int cmpD(const void* a, const void* b){
	return *((int *)b) - *((int *)a);
}

