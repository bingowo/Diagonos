#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double cmp (const void* a, const void *b);

struct data{
	double Alpha[26];
	char sent;
	int pl;
};



int main(int argc, char *argv[]) {
	int T;//问题数目
	scanf("%d",&T);
	double alphabet[26];
	int i;
	for (i = 0; i < T; i++){ //开始分析每一个问题 
		int j;
		for (j = 0; j < 26; j++){
		scanf("%f",alphabet[j]);
		}//先获取字母表对应频率 
		struct data Array[100];
		for (j = 0; j < 100; j++){
			int k;
			for (k = 0; k < 26; k++){
				Array[j].Alpha[k] = alphabet[k];
			}
		} 
		int l = 0;
		char sentence;
		scanf("%s",sentence); 
		while (scanf("%c",Array[l].sent) != EOF){
			l++;
		}
		int lengthOfSentence = l;
		qsort(Array,l,sizeof(Array[0]),cmp);
		int m;
		for (m = 0; m < l; m++){
			printf("%c",Array[m].sent);
		} 
	}
	return 0;
}

double cmp (const void* a, const void *b){
	struct data s1 = *((struct data*)a);
	struct data s2 = *((struct data*)b);
	int pl1, pl2, sign1, sign2;
	if (s1.sent >=  'a' && s1.sent <= 'z'){
		pl1 = s1.sent - 'a' + 1;
		sign1 = 1;
	}else if(s1.sent >= 'A' && s1.sent <= 'Z'){
		pl1 = s1.sent - 'A' + 1;
		sign1 = 2;
	}
	if (s2.sent >=  'a' && s2.sent <= 'z'){
		pl2 = s2.sent - 'a' + 1;
		sign2 = 1;
	}else if(s2.sent >= 'A' && s2.sent <= 'Z'){
		pl2 = s2.sent - 'A' + 1;
		sign2 = 2; 
	}
	if (s1.Alpha[pl1 - 1] != s2.Alpha[pl2 - 1]){
		return s1.Alpha[pl1 - 1] - s2.Alpha[pl2 - 1];
	}else{
		return sign1 - sign2;
	}
	
}