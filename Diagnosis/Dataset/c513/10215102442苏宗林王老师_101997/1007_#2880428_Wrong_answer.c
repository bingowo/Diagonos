#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int main(){
	int re,num,flag,i,n,t,a[10000],j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		j=0;
		re=0;
		num=0;
		flag=-1;
		while(t>0){
			a[j]=t%2;
			t/=2;
			
			if(a[j]!=flag){
				num++;
				flag=a[j];
			}
			else{
				if(num>re){
					re=num;
				}
				num=0;
				flag=a[j];
			}
			
			//printf("num %d re %d",num,re);
			j++;
		}
		if(num>re){
			re=num;
		}
		printf("case #%d:\n%d\n",i,re);
		
	}
	return 0;
}