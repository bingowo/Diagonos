#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double time[27];
int cmp(const void* a,const void* b){
	char *p1,*p2;
	double n1,n2;
	p1=(char*)a;p2=(char*)b;
	n1=*p1>'Z'?time[*p1-'a']:time[*p1-'A'];
	n2=*p2>'Z'?time[*p2-'a']:time[*p2-'A']; //记录频率
	if(n1!=n2)return n1>n2?-1:1;
	else {
		if(*p1-*p2==32)return -1;
		else if(*p2-*p1==32)return 1;
	}
}
int main() {
	int T,i,j,k;
	char s[101];
	char c;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		k=0;
		for(j=0;j<26;j++)scanf("%lf",&time[j]);
		getchar();
		while((c=getchar())!='\n'){
			s[k++]=c;
		}  
		s[k]='\0';  //输入字符串
		qsort(s,strlen(s),sizeof(s[0]),cmp);  //按照频率排序 
		printf("case #%d:\n",i);
		for(k=0;k<strlen(s);k++){
            printf("%c",s[k]);
		}
		printf("\n");
	}
	return 0;
}