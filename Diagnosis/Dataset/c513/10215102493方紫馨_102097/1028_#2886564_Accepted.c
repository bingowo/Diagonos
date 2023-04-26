#include<stdio.h>
#include<stdlib.h>
int cmpA(const void* p1,const void* p2){
	int a=*((int *)p1);
	int b=*((int *)p2);
	if(a>=b)
		return 1;
	return -1;
}
int cmpD(const void* p1,const void* p2){
	int a=*((int *)p1);
	int b=*((int *)p2);
	if(a>=b)
		return -1;
	return 1;
}
int main()
{
	char ch;
	scanf("%c",&ch);
	int num[100];
	int x[1001]={0},i=0,max=0;
	while(scanf("%d",&num[i])!=EOF){	
		x[num[i]]=1;
		if(num[i]>max)
			max=num[i];
		i++;
	}
	int ret[i],k=0;
	for(int j=0;j<=max;j++){
		if(x[j]==1){
			ret[k]=j;
			k++;
		}
	}
	if(ch=='A')
		qsort(ret,k,sizeof(int),cmpA);
	if(ch=='D')
		qsort(ret,k,sizeof(int),cmpD);
	for(i=0;i<k-1;i++){
		printf("%d ",ret[i]);
	}
	printf("%d",ret[i]);
	return 0;
}