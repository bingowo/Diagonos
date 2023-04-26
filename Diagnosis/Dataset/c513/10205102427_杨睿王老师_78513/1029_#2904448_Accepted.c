#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
int cmp(const void * a,const void* b){
	return *(char*)a-*(char*)b;
}

int main(){
	int i,T;
	scanf("%d",&T);
	char ch=getchar();	
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		char all[201];
		char s[201];
		char res[201];
		for(int y=0;y<201;y++){
			all[y]='\0';
			s[y]='\0';
			res[y]='\0';
		}
		int l=0,ls=0;
		while((ch=getchar())!='\n'){
			all[l]=ch;
			if(!isalpha(ch)){
				res[l]=ch;
			}
			else{
				s[ls]=ch;
				ls++;
			}
			l++;
		}
		qsort(s,ls,sizeof(char),cmp);
		int p=0,q=0;
		while(p<l){
			if(res[p]=='\0'){
				res[p]=s[q];
				q++;
			}
			printf("%c",res[p]);
			p++;
		}
		printf("\n");
	}
}