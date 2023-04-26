#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n;
double freq[300];
char s[10005];
int cmp(const void* a,const void* b){
	char x=*(char*)a,y=*(char*)b;
	if(fabs(freq[x]-freq[y])<1e-12) return 0;
	if(freq[y]>freq[x]) return 1;
	else return -1; 
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		for(int i=0;i<26;i++) 
			scanf("%lf",&freq[i+'A']),freq[i+'a']=freq[i+'A']+0.00000001;
		scanf("%s",s);
		int l=strlen(s);
		qsort(s,l,sizeof(char),cmp);
		printf("case #%d:\n",c);
		printf("%s\n",s);
	}
	return 0;
}