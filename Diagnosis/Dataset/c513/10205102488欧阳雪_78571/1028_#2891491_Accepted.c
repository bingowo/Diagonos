#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*c,const void*d)
{
	return(*(int*)c-*(int*)d);
}
int cmp2(const void*a,const void*b)
{
	return(*(int*)b-*(int*)a);
}
int main()
{
	char flg;
	int num[100]={0};
	scanf("%c",&flg);
	//getchar();
	int temp=0,i=0,cnt=0;
	while(scanf("%d",&temp)!=EOF)
	{
		num[i++]=temp;
	}
	cnt=i;
	if(flg=='A'){
		qsort(num,cnt,sizeof(num[0]),cmp1);
	}
	else{
		qsort(num,cnt,sizeof(num[0]),cmp2);
	}
	printf("%d ",num[0]);
	for(int j=1;j<cnt-1;j++)
	{
		if(num[j]!=num[j-1])printf("%d ",num[j]);
	}
	if(num[cnt-1]!=num[cnt-2]){
		printf("%d",num[cnt-1]);
	}
	return 0;
}