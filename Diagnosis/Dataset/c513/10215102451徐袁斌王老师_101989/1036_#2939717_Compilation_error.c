#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
{
	int a;
	int b;
	int c;
};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(B->c!=A->c) return B->c-A->c;
	else if(B->a!=A->a)return A->a-B->a;
	else return A->b-B->b;
}
int main()
{
	int t,y[100];
	struct stu x[100];
	struct stu *p=x;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&x[i].a,&x[i].b);
		x[i].c=abs(x[i].a)+abs(x[i].b);
	} 
	qsort(p,t,sizeof(struct stu),cmp);
	for(int i=0;i<t-1;i++)
	{
		y[i]=abs(x[i].a-x[i+1].a)+abs(x[i].b-x[i+1].b);
	}
	printf("%d\n",y[0]);
	int i=0,j=1,k=0,ans=0;
	if(y[0]%2==0) j=0;
	else ans=1;
	while(i<t-1&&j!=0)
	{
		while(pow(2,k)-1<y[i])
		{
			k++;
		}
		if((int(pow(2,k))-1-y[i])%2==1)
		{
			j=0;
		}
		else
		{
			ans=ans+k-1;i++;
		}
	}
	printf("%d",ans);
	
	

	
	return 0;
	
	
 } 