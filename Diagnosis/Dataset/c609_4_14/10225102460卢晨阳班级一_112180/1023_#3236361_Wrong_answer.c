#include<stdio.h>
#include<stdlib.h>


typedef struct data{
	int date;
	char month[6];
	int cmonth;
	int year;
}data;

int cmp(const void*a,const void*b){
	data*aa=(data*)a;
	data*bb=(data*)b;
	if(aa->year!=bb->year)
	return aa->year-bb->year;
	else{
		if(aa->cmonth!=bb->cmonth)
		return aa->cmonth-bb->cmonth;
		else
		return aa->date-bb->date;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	char *a[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	for(int i=0;i<T;i++){
		int N;
		scanf("%d",&N);
		data t[N];
		for(int j=0;j<N;j++){
			char p,q;
			scanf("%d%c%c%s%d",&t[j].date,&p,&q,t[j].month,&t[j].year);
			for(int k=0;k<19;k++){
				if(t[j].month==a[k])
				t[j].cmonth=k;
			}
		}
		qsort(t,N,sizeof(t[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<N;j++){
			printf("%d. %s %d\n",t[j].date,t[j].month,t[j].year);
		}
	}	
	return 0;
}