#include<stdio.h>
#include<string.h>
#include<ctype.h>
float a[26];
int cmp(const void*i,const void*j){
	char *x,*y;
	x=(char*)i;
	y=(char*)j;
	if(a[tolower(*x)-97]>a[tolower(*y)-97]) return -1;
	else if(a[tolower(*x)-97]<a[tolower(*y)-97]) return 1;
	else if(a[tolower(*x)-97]==a[tolower(*y)-97]) return strcmp(x,y);
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		int j;
		for(j=0;j<=25;j++){
			scanf("%f",&a[j]);
		}
		char s[200];
		scanf("%s",&s);
		qsort(s,strlen(s),sizeof(char),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",s);
	}
}