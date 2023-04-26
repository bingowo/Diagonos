#include <stdio.h>
#include <stdlib.h>

struct student{
	int grade;
	int a[11];
	char num[12];
	int s;
};

int cmp(const void*a,const void*b)
{
	struct student *p,*q;
	p=(struct student*)a;q=(struct student*)b;
	if((p->grade)>(q->grade)) return -1;
	else if((p->grade)<(q->grade)) return 1;
	else{
		int e=0;
		while(1)
		{
			if((p->num[e]-'0')!=(q->num[e]-'0')) return (p->num[e])-(q->num[e]);
			else e++;
		}
	}
	
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	
		int n,m,g;
		scanf("%d %d %d",&n,&m,&g);
		int f[m],i2;
		for(i2=0;i2<m;i2++) scanf("%d",&f[i2]);
		struct student stu[500];
		int j=0;
		for(j;j<n;j++)
		{
			int d=0;
			scanf("%s %d",stu[j].num,&stu[j].s);
			for(d;d<stu[j].s;d++) scanf("%d",&stu[j].a[d]);
			//printf("%c\n",stu[j].a[0]);
			stu[j].grade=0;
			int w=0;
		
			for(w;w<d;w++)
			{
				int k=(stu[j].a[w])-1;
			//	printf("%d\n",k);
				stu[j].grade=stu[j].grade+f[k];
			//	printf("%d\n",stu[j].grade);
			}
			
		}
		qsort(stu,n,sizeof(stu[0]),cmp);
		printf("case #%d:\n",i);
		int r,x=0;
		for(r=0;r<n;r++){
			if(stu[r].grade>g) x++;
			
		}
		printf("%d\n",x);
		for(r=0;r<n;r++)
		{
			if(stu[r].grade>g) printf("%s %d\n",stu[r].num,stu[r].grade);
		}
	}
	return 0;
}