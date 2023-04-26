#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	long long r;
	long long sides;
}col;
int n,m;
int cmp(const void*a,const void*b){
	col* n1=(col*)a,*n2=(col*)b;
	return n1->sides-n2->sides<0?1:-1;
}
int main()
{
	scanf("%d%d",&n,&m);
	col table[n];long long maxans=0;
	for(int i=0;i<n;i++){
		long long l,h;scanf("%lld%lld",&l,&h);
		table[i].r=l;table[i].sides=2*l*h;
	}
	qsort(table,n,sizeof(table[0]),cmp);
	
	for(int i=0;i<n;i++){
		long long R=table[i].r,out=R*R+table[i].sides;int cnt=0;
		for(int j=0;j<n && cnt<m-1;j++){
			if(table[j].r>R || i==j)continue;
			else {
				cnt++;
				out+=table[j].sides;
			}
		}
		if(maxans<out && cnt==m-1)maxans=out;
	}
	printf("%lld",maxans);
	return 0;
} 