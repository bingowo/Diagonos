#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		printf("case #%d:\n",k);
		char str[61];
		int val[128];
		for(int j=0;j<128;j++){
			val[j]=-1;
		}
		scanf("%s",str);
		val[str[0]]=1;
		int d=0;
		for(int i=1;i<strlen(str);i++){
			if(val[str[i]]==-1){
				val[str[i]]=d;
				if(d==0)
					d+=2;
				else
					d++;
			}
			
		}
		
		long long int num=val[str[0]];
		for(int i=1;i<strlen(str);i++){
			num *= d;
			num += val[str[i]];
		}
		printf("%lld\n",num);
	}
	return 0;
}