#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
void kk(int *a)
{
	int i=0;
	do{
		i++;
		if(a[0]%i==0&&a[1]%i==0)
		{
			a[0]/=i;
			a[1]/=i;
			i=1;
		}
	}while(i<a[1]);
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
			else if((j+1)<=s)
			{
				while((j+1)<=s){
				
					s-=(j+1);
					sum+=1;
				}
				if(s==0) break;
			
				else{
					k=j+1;
					w=s;
					int a[2];
					a[0]=s;
					a[1]=k;
					kk(a);
					if(sum!=0) printf("%d+%d/%d\n",sum,a[0],a[1]);
					else printf("%d/%d\n",a[0],a[1]);
					break;
				}
			}
			
			else{
				k=j+1;
				w=s;
				int a[2];
				a[0]=s;
				a[1]=k;
				kk(a);
				if(sum!=0) printf("%d+%d/%d\n",sum,a[0],a[1]);
				else printf("%d/%d\n",a[0],a[1]);
				break;
			}
			
		}
		else count++;
		
	}
	if(count==n-1||s>=n||s==0){
		while(s>=n){
			sum+=1;
			s-=n;
		}
		if(s==0) printf("%d\n",sum);
		else{
			k=j+1;
			w=s;
			int a[2];
			a[0]=s;
			a[1]=k;
			kk(a);
			if(sum!=0) printf("%d+%d/%d\n",sum,a[0],a[1]);
			else printf("%d/%d\n",a[0],a[1]);
		}
	}
	return 0;
	
	
}