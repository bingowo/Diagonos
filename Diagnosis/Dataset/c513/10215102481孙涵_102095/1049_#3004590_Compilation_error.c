#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct data{
	char m[501];
	char m0[501];
};

typedef struct data Data; 


int cmp(const void *a,const void *b){
    struct data p1,p2;
    p1 = *((struct data*)a);
    p2 = *((struct data*)b);
    return strcmp(p1.m0,p2.m0);
}


int main(){
	int T;
	scanf("%d",&T);
	getchar();
	int i; 
	for(i = 0; i < T; i++){
		char *s;
		s = (char *)malloc(1000);
		int numOfAll = 0;
		gets(s);
		char *p = s;
		Data s0[501];
		while (*p != '\0'){//句子没有结束之前 
			if (isspace(*p) != 0 || ispunct(*p) != 0){
				p++;
			} else{
				char *p2 = p;
				while (isspace(*p2) == 0 && ispunct(*p2) == 0 && *p2 != '\0'){
					p2++;
				}
			}
			int len = p2 - p;
			strncopy(s0[numOfAll].m,s0,len);
			s0[numOfAll].m[len] = '\0';
			strncopy(s0[numOfAll].m0,s0,len);
			s0[numOfAll].m0[len] = '\0';
			numOfAll++;
		}//到这里将单词按照空格和标点符号拆开来然后存在结构体数组的字符串里面 
		int numOfWord = 0;
		int k;
		for (k = 0; k < numOfAll; k++){
			int flag = 0;
			int j;
			for (j = 0; j < numOfWord; j++){
				if (strcmp(s0[k].m,s0[j].m0) == 0){
					flag = 1; 
				}
			}
			if (flag == 0){
				strcpy(s0[num].m0,s0[k].m);
                num++;	
			}
		} 
		qsort(s0,numOfWord,sizeof(s0[0]),cmp); 
		int x;
		printf("case #%d:\n",i);
        for(x = 0;x < numOfWord;x++){
            printf("%s ",s0[x].m0);
        }
        printf("\n");
	} 
	return 0;
}



 