#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	long long s;
	long long sides;
}col;
int n,m;
void swap(long long *a,long long *b)
{
	long long temp=*a;*a=*b;*b=temp;
}
long long * Max(col* s,int size){
	long long *ret=(long long*)malloc(sizeof(long long)*m);
	for(int i=1;i<m;i++)ret[i]=0;
	for(int i=0;i<size;i++){
		long long temp;int pos=1;
		if(s[i].sides>ret[1]){
			temp=ret[1];
			ret[1]=s[i].sides;
		}
		else{
			temp=s[i].sides;
		}
		while(pos*2<m){
			long long *maxer=ret[pos*2]>ret[pos*2+1]?&ret[pos*2]:&ret[pos*2+1];
			if(temp>*maxer)swap(&temp,maxer);
			pos*=2;
		}
	}
	return ret;
}
int cmp(const void*a,const void*b){
	col* n1=(col*)a,*n2=(col*)b;
	return n1->s-n2->s<0?1:-1;
}
int main()
{
	scanf("%d%d",&n,&m);
	col table[n];long long maxans=0;
	for(int i=0;i<n;i++){
		long long r,h;scanf("%lld%lld",&r,&h);
		table[i].s=r*r;table[i].sides=2*r*h;
	}
	qsort(table,n,sizeof(table[0]),cmp);
	for(int i=0;i<m;i++){
		long long out=table[i].s+table[i].sides;
		long long *list=Max(table+i+1,n-i-1);
		for(int j=1;j<m;j++){
			out+=list[j];
		}
		if(out>maxans)maxans=out;
		free(list);
	}
	printf("%lld",maxans);
	return 0;
} 