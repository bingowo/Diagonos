#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n,s;
	scanf("%d %d",&n,&s);
	int i=0,a[1000],sum;
	for(i;i<n;i++) scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	//printf("%d %d\n",a[0],a[1]);
	sum=a[0];
	int j=0,k,w,count=0;
	for(j;j<n-1;j++)
	{
		int res;
		if(a[j]!=a[j+1])
		{
			res=a[j+1]-a[j];
			if(res*(j+1)<=s){
				s=s-res*(j+1);
				sum+=a[j+1]-a[j];
				if(s==0) break;
			}
			else{
				k=j+1;
				w=s;
				if(!(k%w)){
					k/=w;
					w=1;
					
				}
				printf("%d+%d/%d\n",sum,w,k);
				break;
			}
			
		}
		else count++;
		
	}
	if(count==n-1){
		if(s>=n){
			if(!(s%n)) sum+=(s/n);
			printf("%d\n",sum);
		}
		else{
			if(!(n%s)){
				s=1;
				n/=s;
				
			}
			printf("%d+%d/%d\n",sum,s,n);
		}
	}
	if(s==0) printf("%d\n",sum);
	return 0;
	
	
}