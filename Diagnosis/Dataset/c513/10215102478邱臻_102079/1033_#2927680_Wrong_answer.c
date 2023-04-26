#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct maya{
	int year;
	int date;
	char month[7];
	int day;  //总共的天数 
};
int mon(char *month){
	char* m[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"}; 
	int i;
	for(i=0;;i++){
		if(!strcmp(month,m[i]))return i;  //字符串转换为月份 
	}
}
int cmp(const void* a,const void* b){
	struct maya p1,p2;
	p1=*(struct maya*)a;p2=*(struct maya*)b;
	return p1.day-p2.day;
	
}
int main() {
	int t,i,j,n;
    struct maya a[10001];   //储存日期 
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);  //日期的数量
		for(j=0;j<n;j++){
			scanf("%d.%s %d",&a[j].date,a[j].month,&a[j].year);  //输入日期
			a[j].day=a[j].date+a[j].year*1000+mon(a[j].month)*20; 
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("%d.%s %d\n",a[j].date,a[j].month,a[j].year);
		}
	}
	return 0;
}