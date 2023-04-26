#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int day;
	char month[7];
	int year;
}MAYA;
char *dic[19] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};//months
int cmp(const void* p1, const void* p2);

int main(void)
{
	int T;
	scanf("%d",&T);
	
	for(int i = 0; i < T; i++){
		int N;
        scanf("%d",&N);
        MAYA data[N];

        for(int v = 0; v < N; v++){//read
            scanf("%d.",&data[v].day);
            scanf("%s",data[v].month);
            scanf("%d",&data[v].year);
        }

		qsort(data,N,sizeof(MAYA),cmp);

		printf("case #%d:\n",i);
		for(int v = 0; v < N; v++){//print
            printf("%d. ",data[v].day);
            printf("%s ",data[v].month);
            printf("%d\n",data[v].year);
        }
	}
	
	return 0;
}
int cmp(const void* p1, const void* p2)
{
	MAYA a = *(MAYA*)p1;
	MAYA b = *(MAYA*)p2;
	
	if(a.year != b.year) return a.year-b.year;
	else if(strcmp(a.month,b.month)){
		int am,bm;
		am = 0, bm = 0;
		for(int i = 0; i < 19; i++){
			if(!strcmp(dic[i],a.month)) break;
            am++;
		}
        for(int i = 0; i < 19; i++){
			if(!strcmp(dic[i],b.month)) break;
            bm++;
		}
        return am - bm;
	}
	else return a.day-b.day;
}