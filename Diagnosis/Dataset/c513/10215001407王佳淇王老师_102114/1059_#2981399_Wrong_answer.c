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
	int sum=0;
	for(int v=0;v<n;v++) sum+=high[v];
	if(sum==n*high[0]) {
		if(s%n==0) printf("%d",high[0]+s/n);
		else printf("%d+%d/%d\n",high[0]+s/n,(s%n)/GCD(s%n,n),n/GCD(s%n,n));
	}
	
	else{
	
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
				if(s%gap==0) printf("%d",h+s/gap);
				else printf("%d+%d/%d\n",h+s/gap,(s%gap)/GCD(s%gap,gap),gap/GCD(s%gap,gap));break;
			}
			
		}	
	}
}
return 0;
}