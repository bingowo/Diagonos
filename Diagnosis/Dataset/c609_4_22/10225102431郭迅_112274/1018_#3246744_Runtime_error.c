#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int aa=*(int*)a;
	int bb=*(int*)b;
	if(a>b){
		return 1;
	}
	else if(a<b) return -1;
	else return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int m=0;
	for(int i=0;i<n-1;i+=2){
		m+=a[i+1]-a[i]; 
	}
	printf("%d",m);
 } 