#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	int n;
	int len1,len2;
	int a,b;
	for (i=0;i<T;i++){
		len1=1;
		len2=1;
		printf("case #%d:\n",i);
		scanf("%d",&n);
		while(n>1){
			a=n&1;
			n=n>>1;
			b=n&1;
			if (a!=b){
				len1+=1;
			}
			else{
				if (len2<len1){
					len2=len1;
				}
				len1=1;
				
			}
		}
		if (len2<len1){
			len2=len1;
		}
		printf("%d\n",len2);
	}
	return 0;
	
}