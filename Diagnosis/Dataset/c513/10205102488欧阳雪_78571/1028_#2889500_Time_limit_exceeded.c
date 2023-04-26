#include<stdio.h>
#include<stdlib.h> 
int cmp1(const void*a,const void*b)
{
	return(*(int*)a-*(int*)b);
}
int cmp2(const void*a,const void*b)
{
	return(*(int*)b-*(int*)a);
}
int main()
{
	char flg,c;
	scanf("%c\n",&flg);
	int a[1000]={0},b[1000]={0};
	while((c=getchar())!='\n')
	{
		int temp=0;
		if(c==' '){
			continue;
		}
		while(c!=' '){
			temp*=10;
			temp+=(c-'0');
			c=getchar();
			if(c==' ')goto FLAG1;
			if(c=='\n')break;
		}
		FLAG1:
			a[temp]++;
			//printf("a[]:%d %d\n",temp,a[temp]);
			//printf("temp:%d\n",temp);
	}
	int j=0;
	for(int i=0;i<1000;i++)
	{
		if(a[i]>0){
			//printf("a[i]:%d %d\n",i,a[i]);
			b[j++]=i;
		//	printf("b[]:%d %d\n",j,b[j]);
		}
	}
	if(flg=='A'){
		qsort(b,j,b[0],cmp1);
	}
	if(flg=='D'){
		qsort(b,j,b[0],cmp2);
	}
	for(int k=0;k<j-1;k++)
	{
		printf("%d ",b[k]);
	}
	printf("%d",b[j-1]);
	return 0;
}