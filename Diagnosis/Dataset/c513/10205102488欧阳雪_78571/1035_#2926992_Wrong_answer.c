#include<stdio.h>
#include<stdlib.h>
struct data{
	long long R;
	long long H;
	long long lateral;//侧面积 
	long long surface;
};
struct data c[1000];
int cmp(const void*a,const void*b)//按侧面积大小排序 
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return(c.lateral>d.lateral );
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&c[i].R,&c[i].H );
		c[i].lateral =2*c[i].R*c[i].H ;
		c[i].surface =c[i].lateral +c[i].R *c[i].R ;
	}
	qsort(c,n,sizeof(c[0]),cmp);
	long long m_r_max=0;//找出前m个数最大半径，作为底部
	long long m_la_min=c[0].lateral ;//最小侧面积
	for(int j=0;j<m;j++)
	{
		if(m_r_max<c[j].R ){
			m_r_max=c[j].R ;
		}
		if(m_la_min>c[j].lateral )
		{
			m_la_min=c[j].lateral ;
		}
	}
	long long temp=0;
	for(int k=m;k<n;k++)
	{
		if(c[k].surface >(m_la_min+m_r_max*m_r_max)&&c[k].R >=m_r_max&&c[k].surface >temp)
		{
			temp=c[k].surface ;
		}
    }
    long long all=0;
    for(int j1=0;j1<m;j1++)
    {
    	all+=c[j1].lateral;
	}
	if(temp){
		all-=m_la_min;
		all+=temp;
	}
	else{
		all+=(m_r_max*m_r_max);
	}
	printf("%lld",all);
	return 0;
}