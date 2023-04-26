#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
typedef struct { 
	int val;   //表示日期“大小”的值
	int y;   //年
	int d;   //日
	char m[7];   //玛雅历的月份
} RECORD;
int month2idx(char* m) 
{ int i;
//1-19月份数组，为静态字符串数组
//顺序比较月份字符串，相同则返回编号i
  for (i=0;;i++) if (!strcmp(m,month[i])) return i; 
}
int cmp(const void *a,const void *b)
{
    return ((RECORD*)a)->val - ((RECORD*)b)->val;
}
int main(){
    int number; 
    scanf("%d",&number);
    for(int j=0;j<number;j++){
        int num;
        scanf("%d",&num);
        RECORD a[num];
        for(int i=0;i<num;i++){
             scanf("%d.%s %d\n",&a[i].d, a[i].m, &a[i].y);
             a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a, num, sizeof(RECORD), cmp);
        printf("case #%d:\n",j);
        for (int i=0;i<num;i++)   
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}
