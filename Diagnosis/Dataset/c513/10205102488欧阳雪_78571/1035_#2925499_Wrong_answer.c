#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI acos(-1)
struct data{
	int R;
	int H;
	long long int by;//R*H 
};
struct data a[1000];
int cmp(const void*a,const void*b)
{
	struct data c=*(struct data *)a;
	struct data d=*(struct data *)b;
	if(c.by >d.by )return -1;
	else return 1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].R );
		scanf("%d",&a[i].H );
		a[i].by=a[i].R*a[i].H ;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	long long int sum1=0,sum2=0,ans1=0,ans2=0;
	int maxr1=0,k=0,maxr2=0;
	for(int j=0;j<m;j++)
	{
		sum1+=a[j].by;
		if(a[j].R >maxr2)maxr2=a[j].R;
    }
    //printf("%d\n",a[0].R );
    //printf("sum1,maxr2:%d %d\n",sum1,maxr2);
    for(int t1=0;t1<n;t1++)
    {
    	if(a[t1].R >maxr1)maxr1=a[t1].R,k=t1 ;
	}
    if(k>=m){
    	sum2=sum1-a[m-1].by+a[k].by ; 
	}
    //printf("maxr:%d %d\n",k,maxr );
	ans1=(2*sum1+maxr2*maxr2);
	ans2=(2*sum2+maxr1*maxr1);
	if(ans1>ans2)printf("%lld",ans1);
	else printf("%lld",ans2);
}