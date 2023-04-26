#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
		char s[27]={'\0'};
		while(scanf("%s\n",s)!=EOF){
			int i;
			int p[130]={0};
			for(i=0;i<26;i++) p[s[i]]=i;//字母顺序,注意第一步输入的全为大写字母 
			char str[2300];//需要排列的多个单词 
			gets(str);
			char wor[100][23];
			int n=0,l=0;//n记录单词个数，l记录单词长度 
			i=0;//一定要重置i 
			do{ l=0;//每个单词重新计算长度
			while(str[i]!=' '&&str[i]) wor[n][l++]=str[i++];
			wor[n][l]='\0';//字符串数组一定要最后加'\0' 
			n++;
			if(!str[i]) break;
			else i++; 						
			}while(str[i]);
			int cmp(const void*a,const void*b){//从小到大排序 
				char* aa=(char*)a;
				char* bb=(char*)b;
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