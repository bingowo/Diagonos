#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

char *month[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

struct maya{
	int date;
	char month[8];
	int year;
};

int judgemonth(char a[]){
	int k=0;
	while(month[k]!=a) k++;
}

int cmp(const void* a, const void* b){
	struct maya a1,a2;
	a1=*(struct maya*)a;
	a2=*(struct maya*)b;
	if(a1.year-a2.year)
		return (a1.year-a2.year)>0; 
	else if(strcmp(a1.month,a2.month)){
		return (judgemonth(a1.month)-judgemonth(a2.month))>0;
	}
	else if(a1.date>=a2.date)
		return 1;
	else return -1;
}

int main(){
	int t,i,j; 
	scanf("%d",&t);
	for(i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		struct maya a[MAX];
		for(j=0;j<n;j++){
			scanf("%d",&a[j].date);
			getchar();
			scanf("%s",a[j].month);
			getchar();
			scanf("%d",&a[j].year);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		for(j=0;j<n;j++){
			printf("case #%d:\n%d. %s %d\n",j,a[j].date,a[j].month,a[j].year);
		}
	}
	return 0;
}