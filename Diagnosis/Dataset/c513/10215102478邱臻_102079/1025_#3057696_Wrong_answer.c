#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int list[100]={};
struct string{
	char s[21];
	int num;
};
int cmp(const void*a,const void*b){
	struct string p1,p2;
	p1=*(struct string*)a;p2=*(struct string*)b;
	if(p1.num!=p2.num)return p1.num>p2.num?-1:1;
	else return strcmp(p1.s,p2.s)?1:-1;
}
int main() {
	int t,n,i,j,k;
	struct string a[100];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		getchar();
		for(j=0;j<n;j++){
			for(k=0;k<100;k++)list[k]=0;
			scanf("%s",a[j].s);
			a[j].num=0;
			for(k=0;k<strlen(a[j].s);k++){
				if(list[a[j].s[k]]==0){
					list[a[j].s[k]]++;
					a[j].num++;
				}
			}  //输入字符串 
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)printf("%s\n",a[j].s);
	}
	return 0;
}