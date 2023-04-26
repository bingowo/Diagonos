#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int n,A[100005];
char s[10]; 

int cmp(const void* a,const void* b){
	int x=*(int *)a,y=*(int *)b;
	return x-y;
}
int main() {
	scanf("%s",s);
	while(~scanf("%d",&A[n])) n++;
	qsort(A,n,sizeof(int),cmp);
	
	if(s[0]=='A'){
		for(int i=0;i<n;i++)
			if(i==0||A[i]!=A[i-1]) printf("%d ",A[i]);
	}
	else {
		for(int i=n-1;i>=0;i--)
			if(i==n||A[i]!=A[i+1]) printf("%d ",A[i]);
	}
		
	return 0;
}