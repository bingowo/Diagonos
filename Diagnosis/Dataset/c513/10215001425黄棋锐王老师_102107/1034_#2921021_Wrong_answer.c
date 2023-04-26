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
		int p1,p2;
		if('a'<=aaa&&aaa<='z') p1=aaa-'a';else p1=aaa-'A';
		if('a'<=bbb&&bbb<='z') p2=bbb-'a';else p2=bbb-'A';
		if(p[aaa]<p[bbb]) return 1;
		else if(p[aaa]==p[bbb]) {
			if(p1==p2) return bbb-aaa;
			else return p1-p2;
			
		}
		
			}
			qsort(s,strlen(s),sizeof(s[0]),cmp);
			printf("case #%d:\n",i);
			printf("%s\n",s);
		}
		
		return 0;
}
	