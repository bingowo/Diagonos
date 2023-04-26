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
		if(strcmp(pa,pb)>0) return 1;
		else if(strcmp(pa,pb)<0) return -1;
		else return (strcmp(bb,aa));
		
}
int main(){
	  int i,T,N;
	  	scanf("%d\n",&N);
	  	char **email;//极端情况33333*1000000超出内存，用动态指针数组
	  	email=(char**)malloc(N*sizeof(char*));
	  		char s[1000002];
	  		char*p;
	  	for(i=0;i<N;i++){
	  		scanf("%s",s);
	  		int l=strlen(s);
	  		p=(char*)malloc(l+1);//char字节数为1 
	  		strcpy(p,s);//不可以直接email[i]=p=s,s地址固定 
	  		email[i]=p;//等价于*(email+i)=p 
		  }
		  qsort(email,N,sizeof(email[0]),cmp);
		  for(i=0;i<N;i++) printf("%s\n",email[i]),free(email[i]);
		  free(email);
		return 0;
}