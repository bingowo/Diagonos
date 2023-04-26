#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{    int m,n,i=0,j=0,k=0,g=0;
	int A[502]={0},B[502]={0},C[502]={0},D[502]={0},fa[1002]={0},fb[1002]={0};
	scanf("%d",&m);
	for(i=0;i<m;i++) 
	{    scanf("%d",&A[i]);
		 fa[A[i]]++;
     }
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",&B[i]);
	   fb[B[i]]++;
    }
    for(i=0;i<m;i++)
    { while(fb[A[i]]!=0)
       {    C[j++]=A[i];
       		fb[A[i]]--;
	   }
	}
    for(k=0;k<n;k++)
    {
    	if(fa[B[k]]==0) D[g++]=B[k];
	}
    qsort(D,g,sizeof(int),cmp);
    for(i=0;i<g;i++)
        C[j++]=D[i];
    for(i=0;i<j-1;i++)
          printf("%d ",C[i]);
        printf("%d",C[i]);
	return 0;
}