提交 #2921000
#	送交者	题目	语言	提交时间	评测时间	结果	耗时	内存	评测机
2921000	10215001425	1034. 字符频率	C	2022-03-12 22:55:48	2022-03-12 22:55:49	
Wrong answer: 0
0.006	0.488	Seattle
 C
 Copy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
		int i,T;
		scanf("%d",&T);
		for(i=0;i<T;i++){
			int j;
			double p[200]={0};
			for(j=0;j<26;j++){
				scanf("%lf",&p['a'+j]);
				p['A'+j]=p['a'+j];
			} 
			char s[104]={0};
			scanf("%s",s);
			int cmp(const void*a,const void*b){
		char*aa=(char*)a;
		char*bb=(char*)b;
		char aaa=*aa;
		char bbb=*bb;
		if(p[*aa]<p[*bb]) return 1;
		else if(p[*aa]==p[*bb]&&(aaa-bbb)!=32&&(aaa-bbb)!=-32) return aaa-bbb;
		else if(p[*aa]==p[*bb]&&((aaa-bbb)==32||(aaa-bbb)==-32)) return bbb-aaa;
		else return -1;
			}
			qsort(s,strlen(s),sizeof(s[0]),cmp);
			printf("case #%d:\n",i);
			printf("%s\n",s);
		}
		
		return 0;
}
	