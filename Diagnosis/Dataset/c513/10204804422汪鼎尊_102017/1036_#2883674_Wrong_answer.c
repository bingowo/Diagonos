#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

unsigned long long mdist(long long x1,long long y1,long long x2,long long y2)
{
	unsigned long long i=llabs(x1-x2)+llabs(y1-y2);
	return i;
}

int cmp(const void *a,const void *b)
{
	const long long *l1=(long long*)a,*l2=(long long*)b;
	unsigned long long dist1=mdist(*l1,*(l1+1),0,0),dist2=mdist(*l2,*(l2+1),0,0);
	if(dist1!=dist2)return dist1>dist2?-1:1;
	if(*l1!=*l2)return *l1>*l2?1:-1;
	return *(l1+1)>*(l2+1)?1:-1;
}

int steps(unsigned long long xdist,unsigned long long ydist)
{
	if(xdist%2==1&&ydist%2==1)return -1;
	unsigned long long totaldist=xdist+ydist;
	if(xdist%2==0&&ydist%2==0&&totaldist!=0)return -1;
	if(totaldist==0)return 0;
	int i=63;
	while(((totaldist>>i)&1)!=1)i--;
	//printf("-%llu %llu %d-",xdist,ydist,i+1);
	return i+1;
}

int main()
{
	int i,j=0,k;
	int points=0,num;
	int c,cases;
	long long data[101][2],result=0;
	unsigned long long pow263=pow(2,63);
	
	scanf("%d",&points);
	for(i=0;i<points;i++)scanf("%lld %lld",&data[i][0],&data[i][1]);
	qsort(data,points,2*sizeof(long long),cmp);
	if(llabs(data[0][0]-data[1][0])==pow263&&llabs(data[0][1]-data[1][1])==pow263)printf("18446744073709551616\n");
	else printf("%llu\n",mdist(data[0][0],data[0][1],data[1][0],data[1][1]));
	for(i=0;i<points-1;i++)
	{
		num=steps(llabs(data[i][0]-data[i+1][0]),llabs(data[i][1]-data[i+1][1]));
		if(num==-1)break;
		result+=num;
	}
	printf("%d",result);
	return 0;
}