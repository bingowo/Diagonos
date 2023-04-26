#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

struct Coord{
	double p;
	double angle;
};

int cmp(const void *a, const void *b)
{
	struct Coord *p1=(struct Coord *)a,*p2=(struct Coord *)b;
	if(p1->angle-p2->angle > 0) return 1;
	else if(p1->angle-p2->angle < 0) return -1;
	else 
	{
		if (p1->p-p2->p > 0) return -1;
		else return 1;
	}
}

int main()
{
	int T,t;
	scanf("%d",&T);
	t=T;
	const double pi=acos(-1.0);
	printf("%f\n",pi);
	while (T)
	{
		int N;
		scanf("%d",&N);
		struct Coord coord[N];
		for( int i = 0; i < N; i++)
		{
			double x,y;
			scanf ("%lf%lf",&x,&y);
			coord[i].p = sqrt(x*x+y*y);
			coord[i].angle = atan2(y,x)>=0 ? atan2(y,x) : atan2(y,x)+2*pi;
		}
		qsort(coord,N,sizeof(coord[0]),cmp);
		printf("case #%d:\n",t-T);
		for(int i = 0; i < N; i++) printf("(%.4f,%.4f)\n",coord[i].p,coord[i].angle);
		T--;
	}
	return 0;
} 