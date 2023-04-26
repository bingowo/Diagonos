#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int power[1002];
int cmp(const void*a,const void*b){
	int n1=*((int*)a),n2=*((int*)b);
	if(power[n1]!=power[n2])return -(power[n1]-power[n2]);
	else return n1-n2;
}
int main()
{	
	int a,b;scanf("%d",&a);
	int aa[a];
	for(int i=0;i<a;i++){
		scanf("%d",&aa[i]);
		power[aa[i]]=1060-i;
	}
	scanf("%d",&b);
	int bb[b];
	for(int i=0;i<b;i++)scanf("%d",&bb[i]);
	qsort(bb,b,sizeof(int),cmp);
	for(int i=0;i<b;i++)
	printf("%d ",bb[i]);
	return 0;
}