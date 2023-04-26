#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void*a,const void*b){
	//char **等价于char*[],元素为char*，cmp时a,b取 char** 
		char*aa;
		char*bb;
		aa=*(char**)a;
		bb=*(char**)b;
		char*pa,*pb;
		while(*aa!='@') aa++;
		while(*bb!='@') bb++;
		pa=aa+1;
		pb=bb+1;
		aa=*(char**)a;
		bb=*(char**)b;
	if(strcmp(pa,pb)==0) return strcmp(bb,aa);
	else return strcmp(pa,pb);
		
}
int main(){
	  int i,N,l;
	  	scanf("%d\n",&N);
	  	char **email;//极端情况33333*1000000超出内存，用动态指针数组
	  	email=(char**)malloc(N*sizeof(char*));
	  		char s[1000002];
	  		char*p;
	  	for(i=0;i<N;i++){
	  		scanf("%s",email[i]);
		  }
		  qsort(email,N,sizeof(char*),cmp);
		  for(i=0;i<N;i++) printf("%s\n",email[i]),free(email[i]);
		  free(email);
		return 0;
}