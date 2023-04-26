#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	long long size;
	char name[120];
}file;
int NA(const void*a,const void*b){
	file aa=*(file*)a;
	file bb=*(file*)b;
	return strcmp(aa.name,bb.name);
}
int SI(const void*a,const void*b){
	file aa=*(file*)a;
	file bb=*(file*)b;
	return aa.size-bb.size;
}
int TI(const void*a,const void*b){
	file aa=*(file*)a;
	file bb=*(file*)b;
	if(aa.year!=bb.year) return aa.year-bb.year;
	else {
		if(aa.mon!=bb.mon) return aa.mon-bb.mon;
		else{
			if(aa.day!=bb.day) return aa.day-bb.day;
			else{
				if(aa.hour!=bb.hour) return aa.hour-bb.hour;
				else{
					if(aa.min!=bb.min) return aa.min-bb.min;
					else return -1;
				}
			}
		}
	}
}
 int main()
 {
		int n;
		while(scanf("%d",&n)&&n!=0)
		{
			file f[101];
			int i;
			for(i=0;i<n;i++)
			{
				scanf("%d-%d-%d %d:%d",&f[i].year,&f[i].mon,
				&f[i].day,&f[i].hour,&f[i].min);
				scanf("%lld %s",&f[i].size,f[i].name);
			}
			char li[5];
			char field[8];
			scanf("%s",li);
			scanf("%s",field);
			if(!strcmp(field,"/NAME")) qsort(f,n,sizeof(f[0]),NA);
			else if(!strcmp(field,"/SIZE")) qsort(f,n,sizeof(f[0]),SI);
			else if(!strcmp(field,"/TIME")) qsort(f,n,sizeof(f[0]),TI);
			for(i=0;i<n;i++)
			 {
			printf("%04d-%02d-%02d %02d:%02d%17lld %s\n",f[i].year,
			f[i].mon,f[i].day,f[i].hour,f[i].min,f[i].size,f[i].name);
			}
			printf("\n");
		}
		
		return 0;
}