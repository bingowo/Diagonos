#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
{
	char a[15];
	long long int b;
};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->b!=B->b)
	{
		return A->b-B->b;
	}
	else
	{
		return strcmp(A->a,B->a);
	}
}
int main()
{
	long long int t;
	int c[128];
	struct stu x[10000];
	struct stu *p=x;
	char a[15];
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",a);
		for(int j=0;a[j-1]!='\0';j++)
		{
			x[i].a[j]=a[j];
		}
		for(int j=0;j<128;j++)
		{
			c[j]=-1;
		}
		c[a[0]]=1;
		int j=1,k=0;
		while(a[j]!='\0')
		{
			if(c[a[j]]!=-1){
				j++;
			}
			else{c[a[j]]=k;
				if(k==0){k=k+2;}
				else{k++;}}
		}
		if(k<2){k=2;}
		long long int ans=1;j=1;
		while(a[j]!='\0')
		{
			ans=ans*k+c[a[j]];
			j++;
		}
		x[i].b=ans;
	}
	qsort(p,t,sizeof(struct stu),cmp);
	for(int i=0;i<t;i++)
	{
		printf("%s\n",x[i].a);
	}
	
	
	return 0;
	
	
 } 