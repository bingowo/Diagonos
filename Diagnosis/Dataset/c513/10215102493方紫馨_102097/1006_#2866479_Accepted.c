#include<stdio.h>
int main()
{
	int n,i,j,k;
	scanf("%d",&n);	
	char a[1000];
	long long ret;
	for(j=0;j<n;j++){
		scanf("%s",a);
		ret=0;
		for(i=0;i<strlen(a);i++){
			
			if(a[i]=='-')
				k=-1;
			else if(a[i]=='0') 
				k=0;
			else if(a[i]=='1')
				k=1;
			ret=3*ret+k;
		}
		printf("case #%d:\n",j);
		printf("%lld\n",ret);
		memset(a,0,sizeof(a));
	}
	return 0;
} 