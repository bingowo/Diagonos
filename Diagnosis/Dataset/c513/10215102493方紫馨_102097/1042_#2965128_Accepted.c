#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char s[20];
}STR;

//升序排列 
int cmp1(const void* p1, const void* p2){
	int a = *((int *)p1);
	int b = *((int *)p2);
	return a - b;
}

int cmp2(const void* p1,const void* p2){
	STR *a = (STR*)p1;
	STR *b = (STR*)p2;
	return strcmp(a->s,b->s);	
}

int main()
{
	int T,c;
	scanf("%d",&T);
	c = getchar();
	for(int i=0;i<T;i++){
		int s[20] = {0}, index = 0, map[52] = {0}, id;
		//s用于存储所有种类字符，map用来筛掉相同字符 
		//index保存字符的种数 
		while((c = getchar())!='\n'){
			if(islower(c))
				id = (c - 'a')*2 + 1;
			else
				id = (c - 'A')*2;
			if(map[id]==0){
				s[index] = c;
				index++;
				map[id] = 1;
			}
		}
		int N = 1<<index;	//保存输出的字符串数 
		STR data[N];
		qsort(s, index, sizeof(int), cmp1); 
		for(int j = 1; j < N ;j++){
			int p = 0;
			for(int k = 0;k < index; k++){
				if(j & (1<<k))
					data[j-1].s[p++] = s[k];
			}
			data[j-1].s[p] = '\0';			
		}
		qsort(data, N-1, sizeof(STR), cmp2);
		printf("case #%d:\n",i);
		for(int j=0;j< N-1;j++){
			printf("%s\n",data[j].s);
		}		
	}
	
	return 0; 
} 