#include<stdio.h>
#include<stdlib.h>
int paixu1(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int paixu2(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	char l;
	int a[100]={0};
	int c[100]={0};
	int b[1000]={0};
	int i=0,num=0;
	scanf("%c",&l);
	while(scanf("%d",&a[i])!=-1){
		b[a[i]]++;
		i++;
	}
	for(int j=0;j<1000;j++){
		if(b[j]!=0){
			c[num]=j;
			num++;
		}
	}
	if(l=='A')
	qsort(c,num,sizeof(c[0]),paixu1);
	if(l=='D')
	qsort(c,num,sizeof(c[0]),paixu2);
	for(int k=0;k<num-1;k++){
	    printf("%d ",c[k]);
	}
	printf("%d\n",c[num-1]);
	
	return 0;
 } 