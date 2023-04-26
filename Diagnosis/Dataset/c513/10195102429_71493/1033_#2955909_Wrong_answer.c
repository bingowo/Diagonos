#include <stdio.h>
#include <stdlib.h>

 struct data{
	int val;   //表示日期“大小”的值
	int y;   //年
	int d;   //日
	char m[7];   //玛雅历的月份
};
int month2idx(char* m)
{ int i;
//1-19月份数组，为静态字符串数组
  static char* month[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
//顺序比较月份字符串，相同则返回编号i
  for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}
int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    d1.val=month2idx(d1.m);
    d2.val=month2idx(d2.m);
    if(d1.y==d2.y){
        if(d1.val=d2.val){
            return d1.d<d2.d;
        }
        return d1.val<d2.val;
    }
    return d1.y<d2.y;

}
int main()
{
    struct data p[1001];
   int t;
   scanf("%d",&t);
   for(int cas=0;cas<t;cas++){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%d",&p[i].d);
            scanf("%s",p[i].m);
            scanf("%d",&p[i].y);
    }
    qsort(p, n, sizeof(p[0]), cmp);
    printf("case #%d:\n",cas);
    for (int i=0;i<n;i++)
       printf("%d. %s %d\n",p[i].d,p[i].m,p[i].y);


   }
   return 0;
}
