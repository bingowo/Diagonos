#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
{
	long long int a;
	long long int b;
	unsigned long long int c;
};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(B->c!=A->c)
	{
		if(B->c>A->c) return 1;
		else return -1;
	} 
	else if(B->a!=A->a)
	{
		if(A->a>B->a) return 1;
		else return -1;
	}
	else 
	{
		if(A->b>B->b) return 1;
		else return -1;
	}
}
int main()
{
	unsigned long long int y[100];
	int t;
	struct stu x[100];
	struct stu *p=x;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld %lld",&x[i].a,&x[i].b);
		x[i].c=abs(x[i].a)+abs(x[i].b);
	} 
	qsort(p,t,sizeof(struct stu),cmp);
	for(int i=0;i<t-1;i++)
	{

		y[i]=llabs(x[i].a-x[i+1].a)+llabs(x[i].b-x[i+1].b);
	}
	printf("%llu\n",y[0]);
	long long int i=0,j=1,k=1,ans=0;
	if(y[0]%2==0) j=0;
	while(i<t-1&&j!=0)
	{
		k=1;
		if(y[i]%2==0) break;
		while(pow(2,k)-1<y[i])
		{
			k++;
		}
		
		ans=ans+k;i++;
	}
	printf("%lld",ans);
	

	
	return 0;
	
	
 } 