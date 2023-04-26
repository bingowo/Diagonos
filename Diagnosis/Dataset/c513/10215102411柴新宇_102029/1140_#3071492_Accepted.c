#include <stdio.h>
#include <stdlib.h>
int n,m,len = 0;
struct node
{
	int val,cnt;
}a[11111];
int res[111] = {0};
int pos = 0;
int mycmp(const void* xx,const void* yy){
	int x = *(int*)xx;
	int y = *(int*)yy;
	if(x>y) return 1;
	else return -1;
}
int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			int temp;
			scanf("%d",&temp);
			int flag = 0;
			for(int k=1;k<=len;k++){
				if(temp==a[k].val){
					a[k].cnt++;
					flag = 1;
				}
			}
			if(!flag){
				len++;
				a[len].val = temp;
				a[len].cnt = 1;
			}
		}
	}
	for(int i=1;i<=len;i++){
		if(a[i].cnt==n){
			res[pos++] = a[i].val;
		}
	}
	qsort(res,pos,sizeof(res[0]),mycmp);
	for(int i=0;i<pos;i++) printf("%d ",res[i]);
	return 0;
}
