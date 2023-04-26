#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n;
double freq[300];
char s[10005];
int cmp(const void* a,const void* b){
	char x=*(char*)a,y=*(char*)b;
	if(fabs(freq[x]-freq[y])<1e-9){
		int tmp1,tmp2;
		if(x>='a') tmp1=x-'a'+'A';
		if(y>='a') tmp2=y-'a'+'A';
		if(tmp1!=tmp2) return tmp1-tmp2;
		else return y-x;
	}
	if(freq[y]>freq[x]) return 1;
	else return -1; 
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		for(int i=0;i<26;i++) 
			scanf("%lf",&freq[i+'A']),freq[i+'a']=freq[i+'A'];
		scanf("%s",s);
		int l=strlen(s);
		qsort(s,l,sizeof(char),cmp);
		printf("case #%d:\n",c);
		printf("%s\n",s);
	}
	return 0;
}