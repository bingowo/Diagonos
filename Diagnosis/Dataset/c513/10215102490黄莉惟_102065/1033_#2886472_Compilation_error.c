#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct { 
	int val;   //表示日期“大小”的值
	int y;   //年
	int d;   //日
	char m[7];   //玛雅历的月份
} RECORD;
int month2idx(char* m)
{  
   //1-19月份数组，为静态字符串数组    
   static char* month[]   =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};   
 
    for (int i=0;; i++)     
          if (!strcmp(m,month[i])) return i;   //返回月份编号i  
}
void Input(RECORD a[],int N){
    for (int i=0;i<N;i++)
    {
     //输入日月年
      scanf("%d.%s %d", &a[i].d, a[i].m, &a[i].y);
      a[i].val = a[i].y*1000 + month2idx(a[i].m)*20 + a[i].d;
    }

}
int cmp(const void* a,const void* b) 
{ 
    return ((RECORD*)a)->val - ((RECORD*)b)->val;
}
int main() {
    int i, n,t,j;
    scanf("%d\n", &t);
    for(j=0;j<t;j++){
        scanf("%d\n", &n);
        RECORD a[n];
        Input(a,n);
        qsort(a, N, sizeof(RECORD), cmp);
        for (i = 0; i < n; i++)
            printf("%d.%s %d", a[i].d, a[i].m, a[i].y);
        return 0;
    }
    
} 

