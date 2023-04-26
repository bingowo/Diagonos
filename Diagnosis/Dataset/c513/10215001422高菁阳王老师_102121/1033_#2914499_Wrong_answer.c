#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
		int val;
		int y;
		int d;
		char m[7];
	}RECORD;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void *a,const void *b){
return ((RECORD*)a)->val - ((RECORD*)b)->val; }
int month2idx(char*m){
 int i;
//1-19月份数组，为静态字符串数组
  static char* month[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
//顺序比较月份字符串，相同则返回编号i
  for (i=0;;i++) if (!strcmp(m,month[i])) return i; 
}

int main(int argc, char *argv[]) {
	typedef struct{
		int val;
		int y;
		int d;
		char m[7];
	}RECORD;
 RECORD a[11];
	int n,m,k;
	scanf("%d\n",&n);
	for(k=0;k<n;k++){
		scanf("%d\n",&m);
		printf("case #%d:\n",k);
		for (int i=0;i<m;i++) {
  //输入日月年
  scanf("%d. %s %d\n", &a[i].d, a[i].m, &a[i].y);
 a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;

	}qsort(a,m,sizeof(RECORD),cmp);
	for(int j=0;j<m;j++)
	printf("%d. %s %d\n", &a[j].d, a[j].m, &a[j].y);}
	return 0;

}
