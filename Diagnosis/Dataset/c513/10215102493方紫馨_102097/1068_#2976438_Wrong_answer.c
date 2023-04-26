#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1){
		if(m==1){
			long long int a = pow(2,n)-1;
			printf("%lld\n",a);
		}
		if(m!=1){
			long long int ret[n+2],i = m;
			ret[m] = 1;
			int d = 1;		
			for(i=m+1;i<=n;i++){			
				ret[i] = 2*ret[i-1] + d;
				d = d*2;
			}
			printf("%lld\n",ret[n]);
		}
	}
	
	return 0;
 } 