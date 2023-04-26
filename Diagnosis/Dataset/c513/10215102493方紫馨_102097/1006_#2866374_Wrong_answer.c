#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);	
	char a[1000],ret=0;
	for(j=0;j<n;j++){
		scanf("%s",a);
		for(i=0;i<strlen(a);i++){
			if(a[i]=='-')
				a[i]=-1;
			ret=3*ret+a[i];
		}
		printf("case #%d:\n",j);
		printf("%d\n",ret);
		memset(a,0,sizeof(a));
	}
	return 0;
} 