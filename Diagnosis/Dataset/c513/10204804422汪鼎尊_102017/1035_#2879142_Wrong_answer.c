#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	const long long *i1=(long long*)a,*i2=(long long*)b;
	long long s1=(*i1)*(*i1)+2*(*i1)*(*(i1+1)),s2=(*i2)*(*i2)+2*(*i2)*(*(i2+1));
	//printf("-%lld-%lld-",(*i1)*(*i1),2*(*i1)*(*(i1+1)));
	if(s1!=s2)return s1>s2?-1:1;
	return *(i2+1)-*(i1+1);
}


int main()
{
	int i,j=0,k;
	int len=0,num;
	int c,cases;
	long long data[1000][2],result=0;
	memset(data,0,2000*sizeof(long long));
	scanf("%d %d",&len,&num);
	for(i=0;i<len;i++)scanf("%lld %lld",&data[i][0],&data[i][1]);
	qsort(data,len,2*sizeof(long long),cmp);//printf("-%d-",data[0][0]);
	for(i=0;i<num;i++)result=result+2*data[i][0]*data[i][1];
	result+=data[0][0]*data[0][0];
	printf("%lld",result);
	return 0;
}