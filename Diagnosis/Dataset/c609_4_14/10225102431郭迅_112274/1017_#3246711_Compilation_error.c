#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<stdlib.h>
int cmp1(const void*a,const void*b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	if(x-y){
		return x-y;//shengxu
	}
	else return 0;
}
int cmp2(const void*a,const void*b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	if(x-y){
		return y-x;//jiangxu
	}
	else return 0;
}
int main()
{
	char c;
	scanf("%c",&c);
	int a[100];
	int i=0;
	for(i=0;scanf("%d",&a[i])!=EOF;i++);
	printf("%d\n",i);
	if(c=='A') 
	{
	if(i==1){printf("%d",a[0]);	}
	else {qsort(a,i,sizeof(int),cmp1);}//升序 
	}
	else 
	{
		if(i==1){printf("%d",a[0]);	}
	else {qsort(a,i,sizeof(int),cmp2);}//降序 
	}
	for(int j=0;j<i-1;j++){
	    if(a[j]==a[j+1])continue;
	    else printf("%d ",a[j];)
	}