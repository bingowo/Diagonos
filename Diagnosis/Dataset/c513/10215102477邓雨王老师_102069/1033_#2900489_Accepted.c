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
int cmp(const void* a,const void* b){
	record x,y;
	x=*(record*)a;
	y=*(record*)b;
	if(x.val>y.val) return 1;
	else return -1;
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		int n;
		scanf("%d",&n);
		record a[n];
		int j;
		for(j=0;j<n;j++){
		scanf("%d.%s %d\n", &a[j].d, a[j].m, &a[j].y);
		a[j].val = a[j].y*1000+month2idx(a[j].m)*20+a[j].d;
		}
	    qsort(a, n, sizeof(record), cmp);
	    printf("case #%d:\n",i);
        for (j=0;j<n;j++){
            printf("%d. %s %d\n",a[j].d,a[j].m,a[j].y);
	}
}
}