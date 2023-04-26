#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <math.h>
typedef  long long int ll;
typedef struct num{
	int v;
	ll number;
	int flag;
	int cnt;
}N;
int cmp(const void * x,const void* y){
	N xx = *(N*) x;
	N yy = *(N*) y;
	if(xx.v==yy.v){
		if(xx.flag==yy.flag){
			if(xx.cnt==yy.cnt) return xx.number-yy.number;
			else return xx.cnt-yy.cnt; 
		}
		else return xx.flag-yy.flag;
	}
	else return yy.v-xx.v;
}

int main(){
	int i,T;
	scanf("%d",&T);
	char ch=getchar();	
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		int n;
		scanf("%d",&n);
		N a[10001];
		for(int j=0;j<10001;j++){
			a[j].flag=0;
			a[j].number=0;
			a[j].v=0;
		}
		//N* a = (N*)malloc(sizeof(N)*(n+1));
		for(int y=0;y<n;y++){
			ll temp;
			scanf("%lld",&temp);
			a[y].number=temp;		
			if(temp<0){
				a[y].flag=-1;
				temp=-temp;
			}
			else{
				a[y].flag=1;
			}
			//printf("test temp:%lld\n",temp);	
			while(temp>0){
				a[y].v=temp;
				a[y].cnt++;
				temp/=10;
			}
			//printf("test v:%d\n",a[y].v);
			//printf("test cnt:%d\n",a[y].cnt);
		}
		qsort(a,n,sizeof(N),cmp);
		for(int y=0;y<n-1;y++){
			printf("%lld ",a[y].number); 
		}
		printf("%lld\n",a[n-1].number);
		//free(a);
	}
}