#include <stdio.h>
typedef struct num{
	int v;
	int cnt;
}N;
/*int CNT(long long number)
{
	int cnt=0;
	int a[65];
	long long test=1;
	for (int i=0;i<64;i++)
	{
		if (number & test){
			//cout<<number<<endl;
			cnt++;			
		}
		a[i]=number & test;	
		test<<=1;
	}

	return cnt;
}*/
int ONE(int a){
	int cnt=0,b[70],q=0,w=0;
	for(q=0;q<70;q++){
		b[q]=-1;
	}
	while(a>0){
		if(a%2) cnt++;
		a/=2;
	}
	return cnt;
}
int NONE(int a){
	a=-a;
	int cnt=0,b[70],q=0,w=0;
	for(q=0;q<70;q++){
		b[q]=1;
	}
	while(a>0){
		b[w]=a%2;
		if(b[w]==1){
			b[w]=0;
		}
		else{
			b[w]=1;
		}
		w++;
		a/=2;
	}
	/*for(q=0;q<65;q++){
		printf("%d",b[q]);
	}
	printf("\ntest\n");*/
	
	b[0]++;
	for(q=0;q<70;q++){
		if(b[q]==2){
			b[q]=0;
			b[q+1]++;
		}
		if(b[q]==1) cnt++;
	}
	/*for(q=0;q<65;q++){
		printf("%d",b[q]);
	}
	printf("\ntest\n");*/
	return cnt;
}
int cmp(const void *x,const void *y){
    N xx = *(N*)x;
    N yy = *(N*)y;
    if(yy.cnt>xx.cnt) return 1;
    if(yy.cnt<xx.cnt) return -1; 
    if(yy.cnt==xx.cnt)  return xx.v>yy.v;
}
int main()
{
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		int n;
		scanf("%d",&n);
		//N *a=(N*)malloc(2*sizeof(int));
		N a[10001];
		int j=0;
		for(j=0;j<n;j++){
			scanf("%d",&a[j].v);
			if(a[j].v>=0){
				a[j].cnt=ONE(a[j].v);
			}
			else{
				a[j].cnt=NONE(a[j].v);
			}
		}
		//printf("\ntest\n");
		qsort(a,n,sizeof(N),cmp);
		for(j=0;j<n;j++){
			printf("%d ",a[j].v);
		}	
		printf("\n");	
	}
}