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
 {  char c,p;
 	scanf("%c",&p);
 	int d[101];
 	int n=0,j;
 	for(;(c=getchar()!=EOF);){
 		if(isdigit(c)) d[n++]=c-'0';
	 }
 	if(p=='A') qsort(d,n,sizeof(int),acmp);
 	else if(p=='D') qsort(d,n,sizeof(int),dcmp);
 	for(j=0;j<n-1;j++) printf("%d ",d[j]);
 	     printf("%d",d[j]);
		return 0;
}