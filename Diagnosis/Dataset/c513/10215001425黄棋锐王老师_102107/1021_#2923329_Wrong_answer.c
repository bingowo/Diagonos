#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
		char s[27]={'\0'};
		while(scanf("%s\n",s)!=EOF){
			int i;
			int p[130]={0};
			char* wor[100];
			char* pp;
			for(i=0;i<26;i++) p[s[i]]=i;//字母顺序,注意第一步输入的全为大写字母 
			char str[2300];//需要排列的多个单词 
			int n=0;
			while(scanf("%s",str)!=EOF){
				int l=strlen(str);
				pp=(char*)malloc(l+1);
				strcpy(pp,str);
				wor[n++]=pp;
			}
			int cmp(const void*a,const void*b){//从小到大排序 
				char* aa=*(char**)a;
				char* bb=*(char**)b;
				char aaa;
				char bbb;
				while(*aa&&*bb){
				 	aaa=(*aa)>='a'?*aa-32:*aa;
					bbb=(*bb)>='a'?*bb-32:*bb;
					if(p[aaa]!=p[bbb]) return p[aaa]-p[bbb];
					else aa++,bb++;
					}
					if(*aa==0) return -1;//不会出现同一个单词 
					else return 1;
			}
			qsort(wor,n,sizeof(wor[0]),cmp);
			for(i=0;i<n-1;i++)
			printf("%s ",wor[i]);
			printf("%s\n",wor[i]);
		} 
		return 0;
}