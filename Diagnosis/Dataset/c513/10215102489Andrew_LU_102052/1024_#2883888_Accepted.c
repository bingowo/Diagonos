#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char nam[15];
	long long s;	
}p;
int cmp1(const void *a, const void *b){
	if((*(p*)a).s!=(*(p*)b).s) return (*(p*)a).s<(*(p*)b).s;
	return strcmp((*(p*)a).nam,(*(p*)b).nam); 
}
int main(){
	int t,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		p a[505];
		int n,m,cnt=0;;
		long long g;
		int sc[15];
		scanf("%d%d%lld",&n,&m,&g);
		for(j=1;j<=m;j++){
			scanf("%d",&sc[j]);
		}
		for(j=0;j<n;j++){
			int ss;
			a[j].s=0;
			scanf("%s%d",a[j].nam,&ss);
			for(k=0;k<ss;k++){
				int tt;
				scanf("%d",&tt);
				a[j].s+=sc[tt];
				//printf("%d\n",sc[tt]);
			}
			if(a[j].s>=g) cnt++;
		}
		qsort((void *)a,n,sizeof(a[0]),cmp1);
		printf("case #%d:\n",i);
		printf("%d\n",cnt);
		for(j=0;j<cnt;j++){
			printf("%s %lld\n",a[j].nam,a[j].s);
		}
	}
}