#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int*p1=(int*)a;int*p2=(int*)b;
	return *p2-*p1;
}
int main()
{
	char A[105];
	scanf("%s",A);
	int l=strlen(A);
	int ans[105]={0};
	int k=0,i=0;
	while(i<l)
	{
		if(isdigit(A[i])&&A[i]!='0')
		{
			while(isdigit(A[i])) ans[k]++,i++;
		}
		k++;i++;
	}
	qsort(ans,k,sizeof(int),cmp);
	printf("%d\n",ans[0]);
 } 