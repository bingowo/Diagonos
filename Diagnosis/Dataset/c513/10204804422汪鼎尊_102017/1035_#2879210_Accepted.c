#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmpb(const void *a,const void *b)
{
	const long long *i1=(long long*)a,*i2=(long long*)b;
	long long s1=(*i1),s2=(*i2);
	if(s1!=s2)return s1>s2?-1:1;
	return (int)(*(i2+1)-*(i1+1));
}

int cmps(const void *a,const void *b)
{
	const long long *i1=(long long*)a,*i2=(long long*)b;
	long long s1=2*(*i1)*(*(i1+1)),s2=2*(*i2)*(*(i2+1));
	if(s1!=s2)return s1>s2?-1:1;
	return (int)(*(i2)-*(i1));
}

int main()
{
	int i,j=0,k;
	int len=0,num;
	int c,cases;
	long long data[1000][2],result=0,maxresult=0,two=2;
	memset(data,0,2000*sizeof(long long));
	scanf("%d %d",&len,&num);
	for(i=0;i<len;i++)scanf("%lld %lld",&data[i][0],&data[i][1]);
	do{
		qsort(data[j],len-j,2*sizeof(long long),cmpb);
		result=0;
		result+=(data[j][0]*data[j][0]+two*data[j][0]*data[j][1]);
		qsort(data[j+1],len-j-1,2*sizeof(long long),cmps);
		for(i=j+1;i<num+j;i++)result=result+two*data[i][0]*data[i][1];
		if(result>maxresult)maxresult=result;
		j++;
	}while(j<=len-num);
	printf("%lld",maxresult);
	return 0;
}