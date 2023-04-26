#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct string{
	char s[101];
	int num;
};
int cmp(const void*a,const void*b){
	struct string p1,p2;
	p1=*(struct string*)a;p2=*(struct string*)b;
	if(p1.num!=p2.num)return p1.num>p2.num?1:-1;
	else return strcmp(p1.s,p2.s)?-1:1;
}
int main() {
	struct string a[1000];
	int i=0,j;
	while(scanf("%s",a[i].s)!=EOF){
		a[i].num=-1;
		for(j=0;j<strlen(a[i].s);j++){
			if(isdigit(a[i].s[j])){
				if(a[i].num==-1)a[i].num++;
				a[i].num=a[i].num*10+a[i].s[j]-'0';
			}
		}
		i++;
	}
	qsort(a,i,sizeof(a[0]),cmp);
	for(j=0;j<i;j++){
		printf("%s ",a[j].s);
	}
	return 0;
}