#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<ctype.h>
int cmp1(const void*a,const void*b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	if(x-y){
		return x-y;//shengxu
	}
}
int cmp2(const void*a,const void*b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	if(x-y){
		return y-x;//jiangxu
	}
}
int main()
{
	char c;
	scanf("%c",&c);
	int a[100];
	int i=0;
	while(scanf("%d",a[i])!=EOF)i++;
	if(c=='A')qort(a,i,sizeof(int),cmp1);
	else qort(a,i,sizeof(int),cmp2);
	for(int j=0;j<i;j++){
		printf("%d ",a[j]);
	}	
}