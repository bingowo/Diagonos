#include<stdio.h>
#include<malloc.h>
void print(int a,int b)
{
	int cnt=0;
	if(a<0){
		printf("-");
		a*=-1;}
	int temp=a;
	while(temp>0)
	{
		cnt++;
		temp/=b;
	}
	int* p=(int*)malloc(sizeof(int)*cnt);
	cnt=0;
	while(a>0)
	{
		p[cnt++]=a%b;
		a/=b;
	}
	cnt--;
	for(int i=0;i<=cnt;i++)printf("%c",p[cnt-i]>10?p[cnt-i]+55:p[cnt-i]+48);
	printf("\n");
	free(p);
}
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	int a,b;
	while(cnt<n)
	{
		scanf("%d%d",&a,&b);
		print(a,b);
		cnt++;
	}	
	return 0;
} 