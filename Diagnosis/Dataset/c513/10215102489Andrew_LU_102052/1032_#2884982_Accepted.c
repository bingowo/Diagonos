#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int s[55];
	int len;
}p;
int cmp1(const void *a, const void *b){
	int i;
	int l1=(*(p*)a).len,l2=(*(p*)b).len;
	int l=l1>l2? l2:l1;
	for(i=0;i<l;i++){
		if((*(p*)a).s[i]!=(*(p*)b).s[i]) return (*(p*)a).s[i]<(*(p*)b).s[i];
	}
	return l1<l2;
}
int main(){
	int t,i,j,k;
	scanf("%d",&t);
	p a[1005];
	for(i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			int tt;
			a[j].len=0;
			while(scanf("%d",&tt)){
				if(tt==-1) break;
				else{
					a[j].s[a[j].len]=tt;
					a[j].len++;
				}
			}
		}
		qsort((void *)a,n,sizeof(a[0]),cmp1);
		for(j=0;j<n;j++){
			for(k=0;k<a[j].len;k++){
				printf("%d ",a[j].s[k]);
			}
			printf("\n");
		}	
	}
}