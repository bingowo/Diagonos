#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	char *p1,*p2;
	p1=(char*)a;p2=(char*)b;
	return *p1>*p2?1:-1;
}
int main() {
	int t,i,j,k,z;
	char c;
	char s[210],a[210];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		strcpy(a,"0");strcpy(s,"0");
		gets(s);
		for(j=0,k=0;j<strlen(s);j++){
			if(isalpha(s[j]))a[k++]=s[j];
		}
		qsort(a,k,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0,k=0;j<strlen(s);j++){
			if(isalpha(s[j]))printf("%c",a[k++]);
			else printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}