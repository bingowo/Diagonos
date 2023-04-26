#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* p1,const void* p2){
	char *a = (char*)p1;
	char *b = (char*)p2;
	return strcmp(a,b);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		char s[20];
		char data[1<<16][18];
		char map[128]={0};
		char alph[20]={0};
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++){
			map[s[i]]=1;
		}
		int idx=0;
		for(int i='A';i<='z';i++){
			if(map[i]==1){
				alph[idx++]=i;
			}
		}
		for(int i=1;i<(1<<idx);i++){
			int p=0;
			for(int j=0;j<idx;j++){
				if(i&(1<<j)){
					data[i-1][p++]=alph[j];
				}
			}
			data[i-1][p]='\0';
		}
		qsort(data,(1<<idx)-1,sizeof(data[0]),cmp);
		printf("case #%d:\n",k);
		for(int i=0;i<(1<<idx)-1;i++){
			printf("%s\n",data[i]);
		}
	}
	
	return 0;
}