#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int dcmp(const void*a,const void*b)
{ return *(int*)b-*(int*)a;
}
 int main()
 {  char c;
 	scanf("%d",&c);
 	int d[101];
 	int i=0,j;
 	while(scanf("%d",&d[i++])!=EOF);
 	if(c=='A') qsort(d,i,sizeof(int),acmp);
 	else if(c=='D') qsort(d,i,sizeof(int),dcmp);
 	for(j=0;j<i-1;j++) printf("%d ",d[j]);
 	     printf("%d",d[j]);
		return 0;
}