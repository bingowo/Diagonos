#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int aa=*(int*)a;
	int bb=*(int*)b;
	int x=0,y=0; 
    while(aa){ 
		if(aa&1) x+=1; 
		aa>>=1;}
	while(bb){
		if(bb&1) y+=1;
		bb>>=1;
	}
	if(x-y) return y-x;
	else return aa-bb; 
	}
int main()
{
	int t;scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;scanf("%d",&n);
		int a[n];
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n-1;j++)
		{
			printf("%d ",a[j]);
		}
		printf("%d\n",a[n-1]);
	}
}