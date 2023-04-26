#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int num(char*str){//数字个数 
	char*s=str;
	int sum=0,flag=0;//flag确定是否有数字，特殊情况为只有0 
	while(*s){
		if('0'<=*s&&*s<='9') sum=sum*10+*s-'0',flag=1; 
		s++;
	}
	if(flag==0) return -1;
	else return sum;
}
int main(){
	  char str[101][31];
	  int count=0,i;
		while(scanf("%s",str[count])!=EOF) count++;
		int strnumcmp(const void*a,const void*b){
			char*aa=(char*)a;
			char*bb=(char*)b;
			int aan=num(aa);
			int bbn=num(bb);
			if(aan==bbn) return(strcmp(aa,bb));
			else {
				if(aan>bbn) return 1;
				else return -1;
			}
		} 
		qsort(str,count,sizeof(str[0]),strnumcmp);
		for(i=0;i<count-1;i++) printf("%s ",str[i]);
		printf("%s\n",str[i]);
		
		return 0;
}