#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int GCD(int m,int n){
	if(n<=m&&n==0) return m;
	else if(m<n) return GCD(n,m);
	else return GCD(n,m%n); 
	
}
int cmp(const void*a,const void*b){
	int a1=*(int*)a;
	int b1=*(int*)b;
	if(a1==b1) return 0;
	else return a1>b1?1:-1; 
}
int main(){
	int n,s;
	int high[1000]={0};
	scanf("%d %d\n",&n,&s);
	for(int v=0;v<n;v++)  scanf("%d",&high[v]);
	qsort(high,n,sizeof(int),cmp);
		/*for(int v=0;v<n;v++)  printf("%d\n",high[v]);*/
		high[n]=high[n-1];
	int h=high[0],gap=1,delta=0;
	for(int i=0;i<n;i++){
		if(high[i]==high[i+1]) {gap++;continue;}
		else{
			delta=high[i+1]-high[i];
			if(s>gap*delta){
				s-=gap*delta;
				h+=delta;
				delta=0;
				gap++;
				continue;
			}
			else{
				printf("%d+%d/%d\n",h,s/GCD(s,gap),gap/GCD(s,gap));break;
			}
			
		}	
	}
	

}