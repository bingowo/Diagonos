#include<stdio.h>
#include<string.h>
typedef struct{ 
	int val;   //表示日期“大小”的值
	int y;   //年
	int d;   //日
	char m[7];   //玛雅历的月份
}record;
int month2idx(char* m) 
{ int i;
//1-19月份数组，为静态字符串数组
  static char* month[] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
//顺序比较月份字符串，相同则返回编号i
  for (i=0;;i++) if (!strcmp(m,month[i])) return i; //strcmp的两个参数都是char*，因此次函数的参数是char* 
}
int cmp(const void* a,const void* b) 
{ return ((record*)a)->val - ((record*)b)->val; }
int main(){
	int N;
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++){
		int n;
		scanf("%d",&n);
		record a[n];
		int j;
		for(j=0;j<n;j++){
		scanf("%d.%s %d\n", &a[i].d, a[i].m, &a[i].y);
		a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;}
	qsort(a, N, sizeof(record), cmp);
	printf("case #%d:\n",i);
    for (i=0;i<N;i++) 
    printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);}

}