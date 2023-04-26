#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char str[21];
	int num;
}LETTER;

int cmp(const void* a,const void* b)
{
	LETTER x,y;
	x=*(LETTER*)a;
	y=*(LETTER*)b;
	if (x.num<y.num){
		return 1;
	}
	if(x.num>y.num){
		return -1;
	}
	return strcmp(x.str,y.str);
}

int main()
{
	int T,n,i,j,k;
	scanf("%d",&T);
	for (i=0;i<T;i++){
		printf("case #%d:\n",i);
		scanf("%d",&n);
		LETTER *list;
		list=(LETTER*)malloc(n*sizeof(LETTER));
		for (j=0;j<n;j++){
			int m[26];
			for (k=0;k<26;k++){
				m[k]=0;
			}
			scanf("%s",list[j].str);
			list[j].num=0;
			for (k=0;k<strlen(list[j].str);k++){
				if (m[list[j].str[k]-'A']==0){
					m[list[j].str[k]-'A']=1;
					list[j].num+=1;
				}
			}
		}
		qsort(list,n,sizeof(LETTER),cmp);
		for (j=0;j<n;j++){
			printf("%s\n",list[j].str);
		}
	}
	return 0;
}