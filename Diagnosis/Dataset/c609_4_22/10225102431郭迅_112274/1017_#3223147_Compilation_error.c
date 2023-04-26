#include<stdio.h>
#include<math.h>
#include<string.h> 
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
	while(scanf("%d",a[i])!=EOF) i++;
	if(c=='A') qort(a,i,sizeof(int),cmp1);
	else qort(a,i,sizeof(int),cmp2);
	for(int j=0;j<i-1;j++){
	    if(a[j]==a[j+1]){printf("%d ",a[j]);j++;}
	    else printf("%d ",a[j]);
	}
	if(a[i-2]==a[i-1]);
	else printf("%d",a[i-1]);
}