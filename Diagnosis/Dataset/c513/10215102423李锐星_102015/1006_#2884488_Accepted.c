#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i,sum,j,weight;
	char s[1000];
	for (i=0;i<T;i++){
		scanf("%s",s);
		sum=0;
		weight=1;
		for (j=strlen(s)-1;j>-1;j--){
			if (s[j]=='-'){
				sum+=-1*weight;
			}
			else if(s[j]=='1'){
				sum+=1*weight;
			}
			weight*=3;
		}
		printf("case #%d:\n",i);
		printf("%d\n",sum);
	}
	return 0;
}