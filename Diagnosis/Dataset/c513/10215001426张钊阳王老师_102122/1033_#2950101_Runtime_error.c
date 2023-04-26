
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int val;   //表示日期“大小”的值
	int y;   //年
	int d;   //日
	char m[7];   //玛雅历的月份
} RECORD;

int main()
{
   int month2idx(char* m);
   int cmp(const void* a,const void* b);
   int m;
   RECORD a[3000];
   scanf("%d",&m);
   for(int z=0;z<m;z++)
   {
    int i,n;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
    scanf("%d.%s %d\n", &a[i].d, a[i].m, &a[i].y);
    a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
    }
    qsort(a, n, sizeof(RECORD), cmp);
    printf("case #%d:\n",z);
    for (i=0;i<n;i++)
    printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);

   }
   return 0;
}


int month2idx(char* m)
{ int i;
//1-19月份数组，为静态字符串数组
  static char* month[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
//顺序比较月份字符串，相同则返回编号i
  for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}

int cmp(const void* a,const void* b)
{ return
((RECORD*)a)->val - ((RECORD*)b)->val; }
