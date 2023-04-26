#include<stdio.h>
#include<stdlib.h>
typedef struct {long x;int count;}num;
int cmp(const void *a, const void *b){
	int ma = (*(num*)a).count,mb = (*(num*)b).count  ;
	if(ma == mb) 
		return  (*(num*)a).x - (*(num*)b).x;//位数不同则升序
	else
		return mb - ma;		//位数相同则降序
}
void count_1(num* p){
	long a = p->x;
	int xa[64]={0};
	int b=0,j=0,flag=1;
	if(a < 0){
		xa[63]=1,a=-a;
		for(int i=0;i<63;i++){
			int tem = a % 2;
			xa[i] = ~tem;
			a/=2;
			if(a==0) break;
		}
		printf("0\n");
		do{
			if(xa[j] + flag == 2)
				xa[j]=0;
			else{
				flag=0,xa[j]=1;
				break;
			}
			j++;
		}while(j<=63);
	}else{
		xa[63]=0;
		do{
			xa[j++] = a % 2;
			a/=2;
		}while(a);
	}
	for(int i=0;i<=j;i++){
		if(xa[i] & 1 == 1)
			b++;
	}
	
	p->count = b;
}
int main(){
	int t,n;
	scanf("%d ",&t);
	
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		num *p=(num *)malloc(n*sizeof(long));
		for(int j=0;j<n;j++){
			scanf("%ld",&((p+j)->x));
			
			count_1(p+j);
		}
		qsort(p,n,sizeof(p[0]),cmp);
		
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++){
			printf("%ld%c",(p+j)->x,j==n-1?'\n':' ');
		}
		free(p);
	}
	return 0;
}